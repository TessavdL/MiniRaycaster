/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 14:43:43 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/24 11:06:46 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
