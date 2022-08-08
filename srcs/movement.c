/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 19:07:01 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 13:09:33 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	rotate(t_data *data, int rot)
{
	double	old_dir_x;
	double	old_plane_x;

	data->keys.press = 1;
	data->player.angle = fix_angle(data->player.angle + (ROT_SPEED * rot));
	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(ROT_SPEED * rot)
		- data->player.dir.y * sin(ROT_SPEED * rot);
	data->player.dir.y = old_dir_x * sin(ROT_SPEED * rot)
		+ data->player.dir.y * cos(ROT_SPEED * rot);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(ROT_SPEED * rot)
		- data->player.plane.y * sin(ROT_SPEED * rot);
	data->player.plane.y = old_plane_x * sin(ROT_SPEED * rot)
		+ data->player.plane.y * cos(ROT_SPEED * rot);
}

static void	move_hor(t_data *data, int dir)
{
	double	next_x;
	double	next_y;

	data->keys.press = 1;
	if (dir == -1)
	{
		next_x = data->player.pos.x - data->player.plane.x * MOVE_SPEED;
		next_y = data->player.pos.y - data->player.plane.y * MOVE_SPEED;
	}
	else
	{
		next_x = data->player.pos.x + data->player.plane.x * MOVE_SPEED;
		next_y = data->player.pos.y + data->player.plane.y * MOVE_SPEED;
	}
	if (data->player.map[(int)next_x][data->player.ipos.y] == '0')
	{
		data->player.pos.x = next_x;
		data->player.ipos.x = (int)next_x;
	}
	if (data->player.map[data->player.ipos.x][(int)next_y] == '0')
	{
		data->player.pos.y = next_y;
		data->player.ipos.y = (int)next_y;
	}
}

static void	move_vert(t_data *data, int dir)
{
	double	next_x;
	double	next_y;

	data->keys.press = 1;
	if (dir == -1)
	{
		next_x = data->player.pos.x - data->player.dir.x * MOVE_SPEED;
		next_y = data->player.pos.y - data->player.dir.y * MOVE_SPEED;
	}
	else
	{
		next_x = data->player.pos.x + data->player.dir.x * MOVE_SPEED;
		next_y = data->player.pos.y + data->player.dir.y * MOVE_SPEED;
	}
	if (data->player.map[(int)next_x][data->player.ipos.y] == '0')
	{
		data->player.pos.x = next_x;
		data->player.ipos.x = (int)next_x;
	}
	if (data->player.map[data->player.ipos.x][(int)next_y] == '0')
	{
		data->player.pos.y = next_y;
		data->player.ipos.y = (int)next_y;
	}
}

int	move(t_data *data)
{
	data->keys.press = 0;
	if (data->keys.rotate_left == 1 && data->keys.rotate_right == 0)
		rotate(data, 1);
	if (data->keys.rotate_right == 1 && data->keys.rotate_left == 0)
		rotate(data, -1);
	if (data->keys.down == 1 && data->keys.up == 0)
		move_vert(data, -1);
	if (data->keys.up == 1 && data->keys.down == 0)
		move_vert(data, 1);
	if (data->keys.left == 1 && data->keys.right == 0)
		move_hor(data, -1);
	if (data->keys.right == 1 && data->keys.left == 0)
		move_hor(data, 1);
	if (data->keys.press == 0)
		return (0);
	raycasting(*data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
	mlx_do_sync(data->mlx.mlx);
	return (0);
}
