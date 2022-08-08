/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils3_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 17:33:20 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 12:58:48 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

char	**ft_split_calloc(char *s, char c, t_ints size)
{
	char	**array;
	char	*temp;
	t_ints	it;

	array = malloc(sizeof(char *) * (size.y + 1));
	if (!array)
		return (NULL);
	it.x = 0;
	temp = s;
	while (it.x < size.y)
	{
		array[it.x] = calloc(size.x + 1, 1);
		if (!array[it.x])
			return (free_array_part(array, it.x));
		it.y = 0;
		while (temp[it.y] != c && temp[it.y] != '\0')
			it.y++;
		if (temp[it.y] == c)
			it.y++;
		ft_strlcpy(array[it.x], temp, it.y);
		temp += it.y;
		it.x++;
	}
	array[it.x] = NULL;
	return (array);
}

static void	ft_strcpy_c(char *dest, char *source, int destlen, char c)
{
	int		i;

	if (!dest || !source)
		return ;
	i = 0;
	while (i < destlen)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
}

char	*ft_strjoin_c(char *s1, char *s2, char c)
{
	char	*s3;
	char	*temp;

	if (!s1)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	temp = s3;
	ft_strcpy_c(temp, s1, ft_strlen(s1), c);
	temp = temp + ft_strlen(s1);
	free(s1);
	ft_strcpy_c(temp, s2, ft_strlen(s2), c);
	return (s3);
}

int	ft_word_count(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (n);
}
