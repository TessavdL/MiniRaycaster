/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 11:53:04 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/28 11:12:13 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_path(t_parser *parser, char *str)
{
	int	i;

	i = is_path(str);
	skip_until_space(&str);
	parser->texture[i] = ft_strtrim(str, " ");
	if (!parser->texture[i])
		return (exit_program("Malloc failed\n"));
}

static void	get_color(t_rgb *colour, char *str)
{
	if (ft_word_count(str, ',') != 3)
		return (exit_program("Invalid cubfile\n"));
	str++;
	colour->r = cub3d_atoi_pointer(&str);
	skip_character(&str, ',');
	colour->g = cub3d_atoi_pointer(&str);
	skip_character(&str, ',');
	colour->b = cub3d_atoi_pointer(&str);
	skip_characters(&str, ' ');
	if (*str != '\0')
	{
		colour->r = -1;
		colour->g = -1;
		colour->b = -1;
	}
}

static void	get_map(t_parser *parser, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (parser->map.begin == FALSE)
	{
		parser->map.string = malloc(sizeof(char) * len + 2);
		if (!parser->map.string)
			return (exit_program("Malloc failed\n"));
		ft_strlcpy(parser->map.string, str, len + 1);
		parser->map.string[len] = '\n';
		parser->map.string[len + 1] = '\0';
		parser->map.begin = TRUE;
		parser->map.size.x = len;
	}
	else if (parser->map.begin == TRUE)
	{
		parser->map.string = ft_strjoin_c(parser->map.string, str, '\n');
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
	skip_characters(&line, ' ');
	count_entries(line, parser->seen, parser->map.begin);
	if (parser->map.begin == TRUE && *temp == '\0')
		parser->map.end = TRUE;
	else if (parser->map.end == TRUE && *temp)
		return (exit_program("Invalid cubfile\n"));
	else if (is_path(line) >= 0)
		get_path(parser, line);
	else if (is_color(line) == CEILING)
		get_color(&parser->ceiling, line);
	else if (is_color(line) == FLOOR)
		get_color(&parser->floor, line);
	else if (is_map(*line) == TRUE)
		get_map(parser, temp);
	else if (*line != '\0')
		return (exit_program("Invalid cubfile\n"));
}
