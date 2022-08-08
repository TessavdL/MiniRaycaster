/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_2d_ray_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 13:20:20 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 11:59:44 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	get_info(t_doubles *delta, double *max, t_ray ray)
{
	*max = 0.0;
	if (ray.dir.x >= 0)
		delta->y *= -1;
	if (ray.dir.x >= 0)
		delta->x *= -1;
	if (fabs(delta->x) > fabs(delta->y))
	{
		if (delta->x > 0)
			*max = delta->x;
		else
			*max = -delta->x;
	}
	else
	{
		if (delta->y > 0)
			*max = delta->y;
		else
			*max = -delta->y;
	}
	delta->x /= *max;
	delta->y /= *max;
}

void	draw_2d_ray(t_data data, t_ints res, t_ray ray, int color)
{
	t_doubles	start;
	t_doubles	delta;
	double		max;
	double		z;
	int			i;

	z = ray.distance / cos((ray.angle_p - ray.angle_r));
	delta.x = (z * -cos(fix_angle(ray.angle_r)) * ray.step.x * (res.x / 64));
	delta.y = (z * sin(fix_angle(ray.angle_r)) * ray.step.x * (res.y / 32));
	get_info(&delta, &max, ray);
	start.x = 4 * (res.x / 64);
	start.y = 4 * (res.y / 32) + (res.y - (res.y / 4));
	i = 0;
	while (i < max)
	{
		if (start.x < 0 || start.x > res.x / 8 || start.y < res.y - (res.y / 4)
			|| start.y > res.y - 1)
			break ;
		put_pixel(&data.img, start.x, start.y, color);
		start.x += delta.x;
		start.y += delta.y;
		i++;
	}
}
