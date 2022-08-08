/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_minimap_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 20:00:08 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 12:01:02 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	get_box_part(int x, int y, t_draw_m *draw)
{
	if (x == -1)
		draw->box.x = draw->tile.x * draw->box.x;
	else if (x == 7)
	{
		draw->start.x = (7 + draw->tile.x) * draw->box.x;
		draw->box.x = (1 - draw->tile.x) * draw->box.x;
	}
	else
		draw->start.x = (x + draw->tile.x) * draw->box.x;
	if (y == -1)
	{
		draw->box.y = draw->tile.y * draw->box.y;
		draw->start.y = draw->offset_y;
	}
	else if (y == 7)
	{
		draw->start.y = ((7 + draw->tile.y) * draw->box.y) + draw->offset_y;
		draw->box.y = (1 - draw->tile.y) * draw->box.y;
	}
	else
		draw->start.y = ((y + draw->tile.y) * draw->box.y) + draw->offset_y;
}

static void	draw_box(t_data data, int x, int y, t_draw_m draw)
{
	int		i;
	int		j;

	if (x == -1 || y == -1 || x == 7 || y == 7)
		get_box_part(x, y, &draw);
	else
	{
		draw.start.x = (x + draw.tile.x) * draw.box.x;
		draw.start.y = (y + draw.tile.y) * draw.box.y + draw.offset_y;
	}
	i = 0;
	while (i < draw.box.x)
	{
		j = 0;
		while (j < draw.box.y)
		{
			put_pixel(&data.img, draw.start.x + i, draw.start.y + j, WHITE);
			j++;
		}
		i++;
	}
}

static void	draw_object(t_data data, double x, double y, int color)
{
	int		i;
	int		j;
	int		radius;
	int		sqrt_radius;
	t_ints	start;

	if (x < 0.5 || y < 0.5 || x > 7.5 || y > 7.5)
		return ;
	start.x = (int)(x * (data.mlx.res.x / 64));
	start.y = (int)(y * (data.mlx.res.y / 32)
			+ (data.mlx.res.y - (data.mlx.res.y / 4)));
	radius = 4;
	sqrt_radius = radius * radius;
	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= sqrt_radius)
				put_pixel(&data.img, start.x + i, start.y + j, color);
			j++;
		}
		i++;
	}
}

static void	get_draw_info(t_data data, t_doubles p, t_draw_m *draw, int *i)
{
	ft_bzero(draw, sizeof(*draw));
	*i = 1;
	draw->tile.x = 1 - (p.y - (int)p.y);
	draw->tile.y = 1 - (p.x - (int)p.x);
	draw->pos.x = p.x - 5.0;
	draw->pos.y = p.y - 5.0;
	draw->box.x = data.mlx.res.x / 64;
	draw->box.y = data.mlx.res.y / 32;
	draw->offset_y = data.mlx.res.y - (data.mlx.res.y / 4);
}

void	draw_minimap(t_data data, t_doubles p, t_ints m_size, char **map)
{
	int			i;
	int			j;
	t_draw_m	draw;

	get_draw_info(data, p, &draw, &i);
	while (i < 10)
	{
		j = 1;
		while (draw.pos.y + i > 0.0 && draw.pos.y + i < m_size.y && j < 10)
		{
			if (draw.pos.x + j > 0.0 && draw.pos.x + j < m_size.x)
			{
				draw.ipos.x = draw.pos.x + j;
				draw.ipos.y = draw.pos.y + i;
				if (map[draw.ipos.x][draw.ipos.y] == '1')
					draw_box(data, i - 2, j - 2, draw);
				else if (map[draw.ipos.x][draw.ipos.y] == '2')
					draw_object(data, i - 1.5 + draw.tile.x,
						j - 1.5 + draw.tile.y, BLUE);
			}
			j++;
		}
		i++;
	}
	draw_object(data, 4.0, 4.0, RED);
}
