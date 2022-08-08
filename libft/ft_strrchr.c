/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:05:20 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 11:31:16 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	i;

	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	i = 0;
	while (s[i] != '\0' && count != 0)
	{
		if (s[i] == c)
			count--;
		i++;
	}
	i--;
	return ((char *)&s[i]);
}
