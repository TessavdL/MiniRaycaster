/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_utils_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 02:06:26 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 11:57:35 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	abbs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	calculate_distance(t_ray *ray)
{
	if (ray->hit_side == 0)
		ray->distance = (ray->ipos.x - ray->pos.x + (1 - ray->step.x) / 2.0)
			/ ray->dir.x;
	else
		ray->distance = (ray->ipos.y - ray->pos.y + (1 - ray->step.y) / 2.0)
			/ ray->dir.y;
}

double	fix_angle(double angle)
{
	if (angle < 0)
		return (angle + TWO_PI);
	if (angle > TWO_PI)
		return (angle - TWO_PI);
	else
		return (angle);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
