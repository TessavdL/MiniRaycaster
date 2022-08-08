/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/24 09:52:43 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/25 14:09:02 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	get_resolution(t_ints *res, char *str)
{
	if (ft_word_count(str, ' ') == 3)
	{
		skip_character(&str, 'R');
		res->x = cub3d_atoi_pointer(&str);
		res->y = cub3d_atoi_pointer(&str);
		skip_characters(&str, ' ');
		if (*str != '\0')
		{
			res->x = -1;
			res->y = -1;
		}
	}
}

static void	get_path(t_parser *parser, char *str)
{
	int	i;

	i = is_path(str);
	skip_until_space(&str);
	parser->texture[i] = ft_strtrim(str, " ");
	if (!parser->texture[i])
		return (exit_program("Malloc failed\n"));
}

static void	get_color(t_parser *parser, char *str)
{
	if (ft_word_count(str, ',') != 3)
		return (exit_program("Invalid cubfile\n"));
	skip_character(&str, 'C');
	parser->ceiling.r = cub3d_atoi_pointer(&str);
	skip_character(&str, ',');
	parser->ceiling.g = cub3d_atoi_pointer(&str);
	skip_character(&str, ',');
	parser->ceiling.b = cub3d_atoi_pointer(&str);
	skip_characters(&str, ' ');
	if (*str != '\0')
	{
		parser->ceiling.r = -1;
		parser->ceiling.g = -1;
		parser->ceiling.b = -1;
	}
}

static void	get_map(t_parser *parser, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (parser->map.begin == FALSE)
	{
		parser->map.string = malloc(sizeof(char) * len + 2);
		if (!parser->map.string)
			return (exit_program("Malloc failed\n"));
		ft_strlcpy(parser->map.string, line, len + 1);
		parser->map.string[len] = '\n';
		parser->map.string[len + 1] = '\0';
		parser->map.begin = TRUE;
		parser->map.size.x = len;
	}
	else if (parser->map.begin == TRUE)
	{
		parser->map.string = ft_strjoin_c(parser->map.string, line, '\n');
		if (!parser->map.string)
			return (exit_program("Malloc failed\n"));
		if (len > parser->map.size.x)
			parser->map.size.x = len;
	}
	parser->map.size.y++;
}

void	parse(t_parser *parser, char *line)
{
	char	*temp;

	temp = line;
	skip_characters(&temp, ' ');
	count_entries(temp, parser->seen, parser->map.begin);
	if (parser->map.begin == TRUE && *temp == '\0')
		parser->map.end = TRUE;
	else if (parser->map.end == TRUE && *temp)
		return (exit_program("Invalid cubfile\n"));
	if (is_resolution(temp))
		get_resolution(&parser->res, temp);
	else if (is_path(temp) != -1)
		get_path(parser, temp);
	else if (is_color(temp))
		get_color(parser, temp);
	else if (is_map(*temp) == TRUE)
		get_map(parser, line);
	else if (*line != '\0')
		return (exit_program("Invalid cubfile\n"));
}
