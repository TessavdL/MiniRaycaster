/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 11:49:19 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 13:09:29 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_pixel(t_img img, int x, int y)
{
	unsigned int	color;
	char			*p;

	if (x < 0 || y < 0)
		return (TRANSPARENT);
	p = img.addr + (y * img.ll + x * (img.bpp / 8));
	color = *(unsigned int *)p;
	return (color);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	set_wall_textures(char *path[4], t_texture texture[4], void *mx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		texture[i].img.img = mlx_xpm_file_to_image(mx, path[i],
				&texture[i].size.x, &texture[i].size.y);
		if (texture[i].img.img == NULL)
			return (exit_program("Failed to convert xpm file to image\n"));
		texture[i].img.addr = mlx_get_data_addr(texture[i].img.img,
				&texture[i].img.bpp, &texture[i].img.ll, &texture[i].img.ndian);
		if (texture[i].img.addr == NULL)
			return (exit_program("Failed to get image address\n"));
		i++;
	}
}
