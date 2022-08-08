/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_error_check_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/28 13:20:28 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/16 15:48:39 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	count_entries(char *line, int seen[8], int map_begin)
{
	if (map_begin == FALSE)
	{
		if (*line == 'R')
			seen[PARSER_RESOLUTION]++;
		if (*line == 'N' && *(line + 1) == 'O')
			seen[PARSER_NORTH]++;
		if (*line == 'S' && *(line + 1) == 'O')
			seen[PARSER_SOUTH]++;
		if (*line == 'W' && *(line + 1) == 'E')
			seen[PARSER_WEST]++;
		if (*line == 'E' && *(line + 1) == 'A')
			seen[PARSER_EAST]++;
		if (*line == 'C')
			seen[PARSER_CEILING]++;
		if (*line == 'F')
			seen[PARSER_FLOOR]++;
		if (*line == 'S' && *(line + 1) == ' ')
			seen[PARSER_SPRITE]++;
	}
}

static t_bool	check_if_entry_count_is_valid(int seen[8])
{
	if (seen[PARSER_RESOLUTION] != 1 || seen[PARSER_NORTH] != 1
		|| seen[PARSER_SOUTH] != 1 || seen[PARSER_WEST] != 1
		|| seen[PARSER_EAST] != 1 || seen[PARSER_CEILING] != 1
		|| seen[PARSER_FLOOR] != 1 || seen[PARSER_SPRITE] != 1)
		return (FALSE);
	return (TRUE);
}

static t_bool	check_if_file_extensions_are_valid(char *texture[])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (check_if_extension_is_valid(texture[i], ".xpm") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_if_input_range_is_valid(t_ints res, t_rgb ceiling)
{
	if (res.y < 1 || res.x < 1)
		return (FALSE);
	if (ceiling.r < 0 || ceiling.b < 0 || ceiling.g < 0 || ceiling.r > 255
		|| ceiling.b > 255 || ceiling.g > 255)
		return (FALSE);
	return (TRUE);
}

t_bool	check_for_parser_errors(t_parser *parser)
{
	if (check_if_entry_count_is_valid(parser->seen) == FALSE)
		return (FALSE);
	if (check_if_input_range_is_valid(parser->res, parser->ceiling) == FALSE)
		return (FALSE);
	if (check_if_file_extensions_are_valid(parser->texture) == FALSE)
		return (FALSE);
	if (check_if_map_is_valid(parser) == FALSE)
		return (FALSE);
	return (TRUE);
}
