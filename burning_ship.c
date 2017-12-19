/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:37:20 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/18 15:38:09 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_burning_ship(t_mlx *mlx)
{
	mlx->x1 = -1.813659;
	mlx->x2 = 1;
	mlx->y1 = -0.086517;
	mlx->y2 = 1.2;
	mlx->image_x = WIN_WIDTH;
	mlx->image_y = WIN_HEIGHT;
	mlx->zoom_x = WIN_WIDTH * 10;
	mlx->zoom_y = WIN_WIDTH * 10;
	mlx->iter_max = 50;
}

static void	ft_burning_ship_iter(t_mlx *mlx)
{
	while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
		&& mlx->i < mlx->iter_max)
	{
		mlx->tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_r = mlx->z_r < 0 ? -mlx->z_r : mlx->z_r;
		mlx->z_i = 2 * mlx->tmp * mlx->z_i + mlx->c_i;
		mlx->z_i = mlx->z_i < 0 ? -1 * mlx->z_i : mlx->z_i;
		mlx->i++;
	}
}

int			ft_draw_burning_ship(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x < mlx->image_x)
	{
		mlx->y = 0;
		while (mlx->y < mlx->image_y)
		{
			mlx->c_r = mlx->x / mlx->zoom_x + mlx->x1;
			mlx->c_i = mlx->y / mlx->zoom_y + mlx->y1;
			mlx->z_r = 0;
			mlx->z_i = 0;
			mlx->i = 0;
			ft_burning_ship_iter(mlx);
			if (mlx->i == mlx->iter_max)
				fill_pixel(mlx->img_str, mlx->x, mlx->y, ORANGE);
			else
				fill_pixel(mlx->img_str, mlx->x, mlx->y,
					get_color(mlx->i, mlx));
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
