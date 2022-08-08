/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/23 16:51:59 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 11:55:42 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_res(void *mlx, int *parser_width, int *parser_height)
{
	int	screen_height;
	int	screen_width;

	mlx_get_screen_size(mlx, &screen_width, &screen_height);
	if (*parser_height > screen_height)
		*parser_height = screen_height;
	if (*parser_width > screen_width)
		*parser_width = screen_width;
}

static void	initialize_cub3d(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		exit_program("Failed to initialize mlx");
	check_res(data->mlx.mlx, &data->mlx.res.x, &data->mlx.res.y);
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.res.x,
			data->mlx.res.y, "cub3D");
	if (!data->mlx.win)
		exit_program("Failed to create window");
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.res.x,
			data->mlx.res.y);
	if (!data->img.img)
		exit_program("Failed to create image");
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.ll, &data->img.ndian);
	if (!data->img.addr)
		exit_program("Failed to get image address");
	set_wall_textures(data->parser.texture, data->paint.texture,
		data->mlx.mlx);
}

void	cub3d(t_data data)
{
	initialize_cub3d(&data);
	raycasting(data);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.img.img, 0, 0);
	mlx_hook(data.mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.mlx.win, 17, 0L, click_x, &data);
	mlx_loop_hook(data.mlx.mlx, &move, &data);
	mlx_loop(data.mlx.mlx);
}
