/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp_bonus.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 18:17:05 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 11:06:50 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	write_to_fd(int fd, const void *buf, int count)
{
	int	w;

	w = write(fd, buf, count);
	if (w == -1)
		exit_program("Failed to write to fd\n");
}

static void	bmp_header(int fd, t_bmp bmp)
{
	write_to_fd(fd, "BM", 2);
	write_to_fd(fd, &bmp.file_size, 4);
	write_to_fd(fd, &bmp.reserved, 2);
	write_to_fd(fd, &bmp.reserved, 2);
	write_to_fd(fd, &bmp.offset, 4);
	write_to_fd(fd, &bmp.header_size, 4);
	write_to_fd(fd, &bmp.image_width, 4);
	write_to_fd(fd, &bmp.image_height, 4);
	write_to_fd(fd, &bmp.planes, 2);
	write_to_fd(fd, &bmp.bpp, 2);
	write_to_fd(fd, &bmp.compression, 4);
	write_to_fd(fd, &bmp.image_size, 4);
	write_to_fd(fd, &bmp.xppm, 4);
	write_to_fd(fd, &bmp.yppm, 4);
	write_to_fd(fd, &bmp.total_colors, 4);
	write_to_fd(fd, &bmp.important_colors, 4);
}

static void	write_pixel_data_to_bmp(int fd, t_bmp bmp, t_data data)
{
	char	c;
	int		x;
	t_ints	size;

	size.x = bmp.image_width;
	size.y = bmp.image_height - 1;
	c = 0x00;
	while (size.y >= 0)
	{
		x = 0;
		while (x < size.x)
		{
			bmp.color = get_pixel(data.img, x, size.y);
			write_to_fd(fd, &bmp.color, 3);
			x++;
		}
		x = 0;
		while (x < bmp.padding)
		{
			write_to_fd(fd, &c, 1);
			x++;
		}
		size.y--;
	}
}

void	create_bmp(t_data data)
{
	int		fd;
	t_bmp	bmp;

	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		exit_program("Failed to open bmp file\n");
	ft_bzero(&bmp, sizeof(bmp));
	bmp.bpp = 24;
	bmp.header_size = 40;
	bmp.image_height = data.mlx.res.y;
	bmp.image_width = data.mlx.res.x;
	if ((bmp.image_width * 3) % 4 != 0)
		bmp.padding = 4 - ((bmp.image_width * 3) % 4);
	bmp.file_size = 54 + (bmp.image_height * bmp.padding)
		+ (bmp.image_width * bmp.image_height * 3);
	bmp.offset = 14 + 40;
	bmp.planes = 1;
	bmp_header(fd, bmp);
	write_pixel_data_to_bmp(fd, bmp, data);
	close(fd);
	exit(0);
}
