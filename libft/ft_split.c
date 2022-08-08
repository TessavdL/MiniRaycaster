/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 10:44:54 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 11:36:45 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	free_array_part(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static int	count_words(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*create_str(const char *s, char c, int i)
{
	char	*word;
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (s[i + len] != c && s[i + len] != '\0')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static	char	**fill_array(char **array, const char *s, char c, int words)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c && s[i] != '\0')
			j++;
		if (s[j] != '\0')
		{
			array[i] = create_str(s, c, j);
			if (!array[i])
			{
				free_array_part(array, i);
				return (NULL);
			}
			i++;
			while (s[j] != c && s[j] != '\0')
				j++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**array;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = fill_array(array, s, c, words);
	return (array);
}
