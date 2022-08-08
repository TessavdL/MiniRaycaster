/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils4.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/28 11:24:29 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/23 14:12:28 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_color(const char *str)
{
	if (!ft_strncmp(str, "C ", 2))
		return (CEILING);
	if (!ft_strncmp(str, "F ", 2))
		return (FLOOR);
	return (NO_COLOUR_TYPE);
}

t_bool	is_empty(char c)
{
	if (c == '0' || c == '\0' || c == ' ')
		return (TRUE);
	return (FALSE);
}

t_bool	is_map(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	is_path(const char *str)
{
	int					i;
	static const char	*path[4] = {"NO ", "SO ", "WE ", "EA "};

	i = 0;
	while (i < 4)
	{
		if (!ft_strncmp(str, path[i], 3))
			return (i);
		i++;
	}
	return (-1);
}

t_bool	is_resolution(const char *str)
{
	if (!ft_strncmp(str, "R ", 2))
		return (TRUE);
	return (FALSE);
}
