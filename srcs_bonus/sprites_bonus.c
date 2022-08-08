/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 20:46:50 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 12:02:29 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	draw_sprites_col(t_data data, t_draw_s draw, int i)
{
	int				d;
	int				j;
	unsigned int	color;

	j = draw.start.y;
	while (j < draw.end.y)
	{
		d = j * 256 - data.mlx.res.y * 128 + draw.height * 128;
		draw.col = ((d * data.sprite.texture.size.y) / draw.height) / 256;
		color = get_pixel(data.sprite.texture.img, draw.row, draw.col);
		if ((color & 0x00FFFFFF) != 0)
			put_pixel(&data.img, i, j, color);
		j++;
	}
}

static void	get_draw_info(t_data data, t_player player, t_draw_s *draw)
{
	draw->transform.x = player.inv
		* (player.dir.y * draw->sprite.x - player.dir.x * draw->sprite.y);
	draw->transform.y = player.inv
		* (-player.plane.y * draw->sprite.x + player.plane.x * draw->sprite.y);
	draw->x = (int)((data.mlx.res.x / 2)
			* (1 + draw->transform.x / draw->transform.y));
	draw->height = abbs((int)((data.mlx.res.y / draw->transform.y)));
	draw->width = draw->height;
	draw->start.y = -draw->height / 2 + data.mlx.res.y / 2;
	if (draw->start.y < 0)
		draw->start.y = 0;
	draw->end.y = draw->height / 2 + data.mlx.res.y / 2;
	if (draw->end.y >= data.mlx.res.y)
		draw->end.y = data.mlx.res.y;
	draw->start.x = -draw->height / 2 + draw->x;
	if (draw->start.x < 0)
		draw->start.x = 0;
	draw->end.x = draw->width / 2 + draw->x;
	if (draw->end.x >= data.mlx.res.x)
		draw->end.x = data.mlx.res.x - 1;
}

static void	sort_sprites(t_sprite2 *sprite, int size)
{
	int			i;
	int			j;
	t_sprite2	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sprite[i].square_distance < sprite[j].square_distance)
			{
				temp = sprite[i];
				sprite[i] = sprite[j];
				sprite[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprites(t_data data, t_player player)
{
	int			i;
	int			n;
	t_draw_s	draw;

	sort_sprites(data.sprite.all, data.sprite.n_visible);
	n = 0;
	while (n < data.sprite.n_visible)
	{
		ft_bzero(&draw, sizeof(draw));
		draw.sprite.x = data.sprite.all[n].ipos.x + 0.5 - player.pos.x;
		draw.sprite.y = data.sprite.all[n].ipos.y + 0.5 - player.pos.y;
		get_draw_info(data, player, &draw);
		i = draw.start.x;
		while (i < draw.end.x)
		{
			draw.row = (int)(256 * (i - (-draw.width / 2 + draw.x))
					* data.sprite.texture.size.x / draw.width) / 256;
			if (draw.transform.y > 0 && i > 0 && i < data.mlx.res.x
				&& draw.transform.y < data.sprite.zbuffer[i])
				draw_sprites_col(data, draw, i);
			i++;
		}
		n++;
	}
}

void	visible_sprite(t_sprite *sprite, t_doubles pos, int x, int y)
{
	int	i;

	i = 0;
	while (i < sprite->n_visible)
	{
		if (sprite->all[i].ipos.x == x && sprite->all[i].ipos.y == y)
			return ;
		i++;
	}
	sprite->n_visible++;
	sprite->all[i].ipos.x = x;
	sprite->all[i].ipos.y = y;
	sprite->all[i].square_distance = ((pos.x - sprite->all[i].ipos.x)
			* (pos.x - sprite->all[i].ipos.x) + (pos.y - sprite->all[i].ipos.y)
			* (pos.y - sprite->all[i].ipos.y));
}
