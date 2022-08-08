/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 17:30:59 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 12:00:13 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	draw_floor2(t_img img, t_draw_f draw, t_ints res, t_texture texture)
{
	int				x;
	unsigned int	color;

	x = 0;
	while (x < res.x)
	{
		draw.ifloor.x = (int)draw.floor.x;
		draw.ifloor.y = (int)draw.floor.y;
		draw.t.x = (int)(texture.size.x * (draw.floor.x - draw.ifloor.x))
			& (texture.size.x - 1);
		draw.t.y = (int)(texture.size.y * (draw.floor.y - draw.ifloor.y))
			& (texture.size.y - 1);
		draw.floor.x += draw.step.x;
		draw.floor.y += draw.step.y;
		color = get_pixel(texture.img, draw.t.y, draw.t.x);
		color = (color >> 1) & 8355711;
		put_pixel(&img, x, draw.y, color);
		x++;
	}
}

void	draw_floor(t_img img, t_player player, t_ints res, t_texture txture)
{
	int			y;
	t_draw_f	draw;

	ft_bzero(&draw, sizeof(draw));
	draw.start.x = player.dir.x - player.plane.x;
	draw.start.y = player.dir.y - player.plane.y;
	draw.end.x = player.dir.x + player.plane.x;
	draw.end.y = player.dir.y + player.plane.y;
	draw.delta.x = draw.end.x - draw.start.x;
	draw.delta.y = draw.end.y - draw.start.y;
	draw.middle_y = res.y / 2;
	y = res.y / 2;
	while (y < res.y)
	{
		draw.y = y;
		draw.pos_y = y - res.y / 2;
		draw.distance = (double)(draw.middle_y / draw.pos_y);
		draw.step.x = draw.distance * draw.delta.x / res.x;
		draw.step.y = draw.distance * draw.delta.y / res.x;
		draw.floor.x = player.pos.x + draw.distance * draw.start.x;
		draw.floor.y = player.pos.y + draw.distance * draw.start.y;
		draw_floor2(img, draw, res, txture);
		y++;
	}
}
