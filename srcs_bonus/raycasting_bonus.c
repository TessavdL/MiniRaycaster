/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 20:25:46 by tevan-de      #+#    #+#                 */
/*   Updated: 2022/08/08 14:50:26 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	last_intercept(char **map, t_sprite *sprite, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->intercept.x < ray->intercept.y)
		{
			ray->intercept.x += ray->delta.x;
			ray->ipos.x += ray->step.x;
			ray->hit_side = 0;
		}
		else
		{
			ray->intercept.y += ray->delta.y;
			ray->ipos.y += ray->step.y;
			ray->hit_side = 1;
		}
		if (map[ray->ipos.x][ray->ipos.y] == '1')
			ray->hit = 1;
		if (map[ray->ipos.x][ray->ipos.y] == '2')
			visible_sprite(sprite, ray->pos, ray->ipos.x, ray->ipos.y);
	}
	calculate_distance(ray);
	sprite->zbuffer[ray->x] = ray->distance;
}

static void	first_intercept(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->intercept.x = (ray->pos.x - ray->ipos.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->intercept.x = (ray->ipos.x + 1.0 - ray->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->intercept.y = (ray->pos.y - ray->ipos.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->intercept.y = (ray->ipos.y + 1.0 - ray->pos.y) * ray->delta.y;
	}
}

static void	initialize_ray(t_data data, t_ray *ray, double increase, int x)
{
	ft_bzero(ray, sizeof(*ray));
	ray->x = x;
	ray->angle_p = data.player.angle;
	ray->angle_r = fix_angle((ray->angle_p + HALF_FOV) - (ray->x * increase));
	ray->camera = 2 * ray->x / (double)data.mlx.res.x - 1;
	ray->dir.x = data.player.dir.x + data.player.plane.x * ray->camera;
	ray->dir.y = data.player.dir.y + data.player.plane.y * ray->camera;
	ray->ipos.x = (int)data.player.pos.x;
	ray->ipos.y = (int)data.player.pos.y;
	ray->pos.x = data.player.pos.x;
	ray->pos.y = data.player.pos.y;
	ray->delta.x = fabs(1.0 / ray->dir.x);
	ray->delta.y = fabs(1.0 / ray->dir.y);
}

void	raycasting(t_data data)
{
	double		increase;
	int			x;
	t_ray		ray;

	increase = FOV / data.mlx.res.x;
	x = 0;
	draw_floor(data.img, data.player, data.mlx.res, data.paint.texture[4]);
	while (x < data.mlx.res.x)
	{
		initialize_ray(data, &ray, increase, x);
		first_intercept(&ray);
		last_intercept(data.player.map, &data.sprite, &ray);
		draw_3d_ray(data.img, data.paint, ray, data.mlx.res);
		x++;
	}
	if (data.sprite.n_visible > 0)
		draw_sprites(data, data.player);
	draw_minimap(data, data.player.pos, data.player.map_size, data.player.map);
}
