/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:49 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/14 17:19:26 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_mlx mlx)
{
	int i;

	mlx.x1 = -2.1;
	mlx.x2 = 0.6;
	mlx.y1 = -1.2;
	mlx.y2 = 1.2;
	mlx.iter_max = 50;
	mlx.image_x = WIN_WIDTH;//(mlx.x2 - mlx.x1) * mlx.zoom;
	mlx.image_y = WIN_HEIGHT;//(mlx.y2 - mlx.y1) * mlx.zoom;

	mlx.x = 0;
	while (mlx.x < mlx.image_x)
	{
		mlx.y = 0;
		while (mlx.y < mlx.image_y)
		{
			mlx.c_r = mlx.x / mlx.zoom + mlx.x1;
			mlx.c_i = mlx.y / mlx.zoom + mlx.y1;
			mlx.z_r = 0;
			mlx.z_i = 0;
			i = 0;
			while (mlx.z_r * mlx.z_r + mlx.z_i * mlx.z_i < 4 && i < mlx.iter_max)
			{
				mlx.tmp = mlx.z_r;
				mlx.z_r = mlx.z_r * mlx.z_r - mlx.z_i * mlx.z_i + mlx.c_r;
				mlx.z_i = 2 * mlx.tmp * mlx.z_i + mlx.c_i;
				i++;
			}
			if (i == mlx.iter_max)
				fill_pixel(mlx.img_str, mlx.x, mlx.y, BLACK);
			else
				fill_pixel(mlx.img_str, mlx.x, mlx.y, BLUE);
			mlx.y++;
		}
		mlx.x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	return (0);
}
