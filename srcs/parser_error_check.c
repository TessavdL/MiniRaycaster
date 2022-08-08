/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_error_check.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 21:57:29 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/28 11:14:11 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	count_entries(char *line, int seen[7], int map_begin)
{
	if (map_begin == FALSE)
	{
		if (*line == 'N' && *(line + 1) == 'O')
			seen[PARSER_NORTH]++;
		else if (*line == 'S' && *(line + 1) == 'O')
			seen[PARSER_SOUTH]++;
		else if (*line == 'W' && *(line + 1) == 'E')
			seen[PARSER_WEST]++;
		else if (*line == 'E' && *(line + 1) == 'A')
			seen[PARSER_EAST]++;
		else if (*line == 'C')
			seen[PARSER_CEILING]++;
		else if (*line == 'F')
			seen[PARSER_FLOOR]++;
	}
}

static t_bool	check_if_entry_count_is_valid(int seen[7])
{
	if (seen[PARSER_NORTH] != 1 || seen[PARSER_SOUTH] != 1
		|| seen[PARSER_WEST] != 1 || seen[PARSER_EAST] != 1
		|| seen[PARSER_CEILING] != 1 || seen[PARSER_FLOOR] != 1)
		return (FALSE);
	return (TRUE);
}

static t_bool	check_if_file_extensions_are_correct(char *texture[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (check_if_extension_is_valid(texture[i], ".xpm") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_if_input_range_is_valid(t_rgb ceiling, t_rgb floor)
{
	if (ceiling.r < 0 || ceiling.b < 0 || ceiling.g < 0 || ceiling.r > 255
		|| ceiling.b > 255 || ceiling.g > 255)
		return (FALSE);
	if (floor.r < 0 || floor.b < 0 || floor.g < 0 || floor.r > 255
		|| floor.b > 255 || floor.g > 255)
		return (FALSE);
	return (TRUE);
}

t_bool	check_for_parser_errors(t_parser *parser)
{
	if (check_if_entry_count_is_valid(parser->seen) == FALSE)
		return (FALSE);
	if (check_if_input_range_is_valid(parser->ceiling, parser->floor) == FALSE)
		return (FALSE);
	if (check_if_file_extensions_are_correct(parser->texture) == FALSE)
		return (FALSE);
	if (check_if_map_is_valid(parser) == FALSE)
		return (FALSE);
	return (TRUE);
}
