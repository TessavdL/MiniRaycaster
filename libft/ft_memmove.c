/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 13:28:11 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 10:58:12 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	sdcopy(unsigned char *d, unsigned const char *s, size_t n, size_t i)
{
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	dscopy(unsigned char *d, unsigned const char *s, size_t n)
{
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	i = 0;
	if (s > d)
		sdcopy(d, s, n, i);
	else if (d > s)
		dscopy(d, s, n);
	return (dst);
}
