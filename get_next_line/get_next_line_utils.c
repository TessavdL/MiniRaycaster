/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 11:59:55 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 14:27:05 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_memmove(void *dst, const void *src, int n)
{
	unsigned char		*d;
	unsigned const char	*s;
	int					i;

	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (dst);
}

int	gnl_strchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (len);
		len++;
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (len);
	return (0);
}

char	*gnl_strdup(char *s1, int len)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (s3)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			s3[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			s3[i + j] = s2[j];
			j++;
		}
		s3[i + j] = '\0';
	}
	free(((void *)s1));
	s1 = NULL;
	return (s3);
}

int	gnl_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
