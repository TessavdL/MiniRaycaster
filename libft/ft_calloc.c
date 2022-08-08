/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 15:14:29 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 10:32:03 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char		*p;
	size_t		i;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (0);
	while (i < (count * size))
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
