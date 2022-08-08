/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 17:51:37 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/16 16:00:02 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	exit_program(char *s)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(s, 1);
	exit(1);
}

void	free_array(char **array, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**free_array_part(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

void	skip_until_space(char **string)
{
	if ((!*string))
		return ;
	while (**string)
	{
		(*string)++;
		if (**string == ' ')
			break ;
	}
}
