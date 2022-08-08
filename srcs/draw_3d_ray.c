/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_3d_ray.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/24 13:28:14 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 11:59:56 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture_type	wall_texture(t_ray ray)
{
	if (ray.hit_side == 0)
	{
		if (ray.dir.x > 0)
			return (TEXTURE_NORTH);
		else
			return (TEXTURE_SOUTH);
	}
	else
	{
		if (ray.dir.y > 0)
			return (TEXTURE_WEST);
		else
			return (TEXTURE_EAST);
	}
}

static void	wall_draw_info(t_draw *draw, t_paint *paint, t_ints res, t_ray ray)
{
	double	wall_row;

	if (ray.distance < 0.01)
		ray.distance = 0.01;
	draw->height = (int)(res.y / ray.distance);
	draw->start = -draw->height / 2 + res.y / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->height / 2 + res.y / 2;
	if (draw->end >= res.y)
		draw->end = res.y;
	draw->texture = &paint->texture[(wall_texture(ray))];
	if (ray.hit_side == 0)
		wall_row = ray.pos.y + ray.distance * ray.dir.y;
	else
		wall_row = ray.pos.x + ray.distance * ray.dir.x;
	wall_row -= floor((wall_row));
	draw->row = (int)(wall_row * draw->texture->size.x);
	if (ray.hit_side == 0 && ray.dir.x > 0)
		draw->row = draw->texture->size.x - draw->row - 1;
	else if (ray.hit_side == 1 && ray.dir.y < 0)
		draw->row = draw->texture->size.x - draw->row - 1;
	draw->step = 1.0 * ((double)draw->texture->size.y / (double)draw->height);
	draw->col = (draw->start - res.y / 2 + draw->height / 2) * draw->step;
}

void	draw_3d_ray(t_img img, t_paint paint, t_ray ray, t_ints res)
{
	t_draw	draw;
	int		y;

	ft_bzero(&draw, sizeof(draw));
	wall_draw_info(&draw, &paint, res, ray);
	y = 0;
	while (y < res.y)
	{
		if (y < draw.start)
			put_pixel(&img, ray.x, y, paint.ceiling);
		else if (y >= draw.start && y < draw.end)
		{
			draw.col += draw.step;
			draw.icol = (int)draw.col;
			if (draw.icol >= draw.texture->size.y)
				draw.icol = draw.texture->size.y - 1;
			draw.color = get_pixel(draw.texture->img, draw.row, draw.icol);
			put_pixel(&img, ray.x, y, draw.color);
		}
		else
			put_pixel(&img, ray.x, y, paint.floor);
		y++;
	}
}
