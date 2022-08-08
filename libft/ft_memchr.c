/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:51:14 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 10:55:52 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*p;
	unsigned const char	*str;
	size_t				i;

	i = 0;
	p = NULL;
	str = s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			p = &str[i];
			break ;
		}
		i++;
	}
	return ((char *)p);
}
