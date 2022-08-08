/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 13:49:54 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 13:09:26 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	click_x(void)
{
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ROTL)
		data->keys.rotate_left = 1;
	if (keycode == KEY_ROTR)
		data->keys.rotate_right = 1;
	if (keycode == KEY_LEFT)
		data->keys.left = 1;
	if (keycode == KEY_RIGHT)
		data->keys.right = 1;
	if (keycode == KEY_UP)
		data->keys.up = 1;
	if (keycode == KEY_DOWN)
		data->keys.down = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_ROTL)
		data->keys.rotate_left = 0;
	if (keycode == KEY_ROTR)
		data->keys.rotate_right = 0;
	if (keycode == KEY_LEFT)
		data->keys.left = 0;
	if (keycode == KEY_RIGHT)
		data->keys.right = 0;
	if (keycode == KEY_UP)
		data->keys.up = 0;
	if (keycode == KEY_DOWN)
		data->keys.down = 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
	return (0);
}
