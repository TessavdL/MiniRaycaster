/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 11:59:06 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 14:27:08 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_and_return(char **ret, int n)
{
	free(*ret);
	*ret = NULL;
	return (n);
}

static int	put_in_line(char **ret, char **line, int newline, int n)
{
	int	len;

	len = (gnl_strlen(*ret) - (newline - 1));
	if (newline == 0)
		newline = len;
	*line = gnl_strdup(*ret, newline - 1);
	if (!*line)
		return (free_and_return(ret, -1));
	if (n != 0)
		*ret = gnl_memmove(*ret, (*ret + newline), len);
	if (n == 0)
		return (free_and_return(ret, 0));
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*ret;
	int			n;

	n = 1;
	if (fd < 0 || !line)
		return (-1);
	if (!ret)
		ret = gnl_strdup("", 0);
	if (!ret)
		return (-1);
	if (ret && (gnl_strchr(ret, '\n') > 0))
		return (put_in_line(&ret, line, gnl_strchr(ret, '\n'), 1));
	while (n > 0 && !gnl_strchr(ret, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (free_and_return(&ret, -1));
		buffer[n] = '\0';
		ret = gnl_strjoin(ret, buffer);
		if (!ret)
			return (-1);
	}
	return (put_in_line(&ret, line, gnl_strchr(ret, '\n'), n));
}
