/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 14:48:12 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/23 15:35:14 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_bool	check_if_map_characters_are_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_map(map[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	get_number_of_players(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	get_player_position(char **map, t_ints *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				player->y = j;
				player->x = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_bool	check_if_map_is_valid(t_parser *parser)
{
	char	**array;

	array = ft_split_calloc(parser->map.string, '\n', parser->map.size);
	if (!array)
		exit_program("Malloc failed\n");
	if (check_if_map_characters_are_valid(array) == FALSE
		|| get_number_of_players(array) != 1)
	{
		free_array(array, parser->map.size.y + 1);
		return (FALSE);
	}
	get_player_position(array, &parser->map.player);
	if (check_if_map_is_closed(array, parser->map) == FALSE)
	{
		free_array(array, parser->map.size.y + 1);
		return (FALSE);
	}
	free_array(array, parser->map.size.y + 1);
	return (TRUE);
}
