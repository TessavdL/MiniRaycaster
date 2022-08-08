/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils2_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 21:50:01 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/02/28 11:39:16 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

t_bool	check_if_extension_is_valid(char *filename, char *extension)
{
	char	*dot_location;
	int		len_filename_extension;

	dot_location = ft_strrchr(filename, '.');
	if (!dot_location)
		return (FALSE);
	len_filename_extension = ft_strlen(dot_location);
	if (len_filename_extension == 0)
		return (FALSE);
	if (ft_strcmp(dot_location, extension))
		return (FALSE);
	return (TRUE);
}

static long int	cub3d_atoi_pointer_continued(char **str, int sign)
{
	unsigned long int	number;

	number = 0;
	while (**str && ft_isdigit(**str))
	{
		if ((number > 922337203685477580 || (number == 922337203685477580
					&& (**str - '0') > 7)) && sign == 1)
			return (-1);
		else if ((number > 922337203685477580 || (number == 922337203685477580
					&& (**str - '0') > 8)) && sign == -1)
			return (0);
		number = number * 10 + (**str - '0');
		(*str)++;
	}
	if (number * sign > 214783647)
		return (214783647);
	return (number * sign);
}

int	cub3d_atoi_pointer(char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-')
		return (-1);
	else if (**str == '+')
		(*str)++;
	if (ft_isdigit(**str) == 0)
		return (-1);
	return (cub3d_atoi_pointer_continued(str, sign));
}

void	skip_character(char **s, char c)
{
	if (!(*s))
		return ;
	if (**s && **s == c)
		(*s)++;
}

void	skip_characters(char **s, char c)
{
	if (!(*s))
		return ;
	while (**s && **s == c)
		(*s)++;
}
