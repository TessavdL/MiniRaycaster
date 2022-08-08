/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:00:28 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 11:37:57 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	beginstr(const char *s1, const char *set)
{
	const char	*begin;
	int			i;
	int			j;

	i = 0;
	j = 0;
	begin = s1;
	while (begin[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (begin[i] != set[j])
				j++;
			else
			{
				i++;
				j = 0;
			}
		}
		if (set[j] == '\0')
			break ;
	}
	return (i);
}

static unsigned int	endstr(const char *s1, const char *set)
{
	const char	*end;
	int			i;
	int			j;

	i = ft_strlen(s1);
	j = 0;
	end = s1;
	while (end[i] != end[0])
	{
		while (set[j] != '\0' && i > 0)
		{
			if (end[i] != set[j] && end[i] != '\0')
				j++;
			else
			{
				i--;
				j = 0;
			}
		}
		if (set[j] == '\0')
			break ;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	int		i;
	int		begin;
	int		end;

	if (!s1)
		return (NULL);
	if (!set || set[0] == '\0')
		return (ft_strdup((char *)s1));
	i = 0;
	begin = beginstr(s1, set);
	end = endstr(s1, set);
	if (begin > end)
		return (ft_strdup(""));
	s2 = malloc(sizeof(char) * (end - begin) + 2);
	if (!s2)
		return (NULL);
	while (s1[begin + i] && i < (end - begin) + 1)
	{
		s2[i] = s1[begin + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
