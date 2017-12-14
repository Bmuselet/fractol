/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:27:15 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/14 18:25:09 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(int *str, int x, int y, int color)
{
	int i;

	i = x + (y * WIN_WIDTH);
	str[i] = color;
}

unsigned int	get_color(int i, t_mlx *mlx)
{
	unsigned int	c;
	unsigned char		r;
	unsigned char	g;
	unsigned char	b;

	r = (i * 4) * mlx->color_value;
	g = (255 - (i * 3)) * mlx->color_value;
	b = (255 - (i * 12)) * mlx->color_value;
	c = (r << 16) + (g << 8) + b;
	return (c);
}
