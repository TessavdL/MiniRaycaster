/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_map_floodfill.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 15:16:11 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 13:09:48 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_bool	check_if_filled(char **array, t_ints size)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'x' &&
				(i > 0 && i < (size.y - 1) && j > 0 && j < (size.x - 1) &&
				(is_empty(array[i + 1][j]) == TRUE ||
				is_empty(array[i + 1][j]) == TRUE ||
				is_empty(array[i][j + 1]) == TRUE ||
				is_empty(array[i][j - 1]) == TRUE ||
				is_empty(array[i + 1][j + 1]) == TRUE ||
				is_empty(array[i + 1][j - 1]) == TRUE ||
				is_empty(array[i - 1][j + 1]) == TRUE ||
				is_empty(array[i - 1][j - 1]) == TRUE)))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static void	mark_surroundings(char **array, t_ints size, int i, int j)
{
	if (i > 0 && i < (size.y - 1) && j > 0 && j < (size.x - 1))
	{
		if (is_empty(array[i + 1][j]) == 1)
			array[i + 1][j] = 'x';
		if (is_empty(array[i - 1][j]) == 1)
			array[i - 1][j] = 'x';
		if (is_empty(array[i][j + 1]) == 1)
			array[i][j + 1] = 'x';
		if (is_empty(array[i][j - 1]) == 1)
			array[i][j - 1] = 'x';
		if (is_empty(array[i + 1][j + 1]) == 1)
			array[i + 1][j + 1] = 'x';
		if (is_empty(array[i + 1][j - 1]) == 1)
			array[i + 1][j - 1] = 'x';
		if (is_empty(array[i - 1][j + 1]) == 1)
			array[i - 1][j + 1] = 'x';
		if (is_empty(array[i - 1][j - 1]) == 1)
			array[i - 1][j - 1] = 'x';
	}
}

static t_bool	mark_path_and_check_if_closed(char **array, t_ints size)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'x' &&
			i > 0 && i < (size.y - 1) && j > 0 && j < (size.x - 1))
				mark_surroundings(array, size, i, j);
			else if (array[i][j] == 'x')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_if_map_is_closed(char **array, t_map map)
{
	t_bool	closed;
	t_bool	filled;

	closed = TRUE;
	filled = FALSE;
	array[map.player.x][map.player.y] = 'x';
	while (filled == FALSE && closed == TRUE)
	{
		filled = check_if_filled(array, map.size);
		closed = mark_path_and_check_if_closed(array, map.size);
	}
	return (closed);
}
