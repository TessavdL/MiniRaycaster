/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils4_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/28 12:07:55 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/23 13:31:34 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	is_color(const char *str)
{
	char	*temp;

	temp = NULL;
	if (!ft_strncmp(str, "C ", 2))
		return (CEILING);
	return (NO_COLOUR_TYPE);
}

t_bool	is_empty(char c)
{
	if (c == '0' || c == '2' || c == '\0' || c == ' ')
		return (TRUE);
	return (FALSE);
}

t_bool	is_map(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	is_path(const char *str)
{
	int					i;
	static const char	*path[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "S "};

	i = 0;
	while (i < 4)
	{
		if (!ft_strncmp(str, path[i], 3))
			return (i);
		i++;
	}
	while (i < 6)
	{
		if (!ft_strncmp(str, path[i], 2))
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
