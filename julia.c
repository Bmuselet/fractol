/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:04:01 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/18 11:23:48 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_julia(t_mlx *mlx)
{
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
	mlx->x1 = -2;
	mlx->x2 = 2;
	mlx->y1 = -1.25;
	mlx->y2 = 1.25;
	mlx->iter_max = 50;
	mlx->image_x = WIN_WIDTH;
	mlx->image_y = WIN_HEIGHT;
	mlx->zoom_x = WIN_WIDTH / (mlx->x2 - mlx->x1);
	mlx->zoom_y = WIN_HEIGHT / (mlx->y2 - mlx->y1);
}

static void	ft_julia_iter(t_mlx *mlx)
{
	while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
		&& mlx->i < mlx->iter_max)
	{
		mlx->tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_i = 2 * mlx->tmp * mlx->z_i + mlx->c_i;
		mlx->i++;
	}
}

int			ft_draw_julia(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x < mlx->image_x)
	{
		mlx->y = 0;
		while (mlx->y < mlx->image_y)
		{
			mlx->z_r = mlx->x / mlx->zoom_x + mlx->x1;
			mlx->z_i = mlx->y / mlx->zoom_y + mlx->y1;
			mlx->i = 0;
			ft_julia_iter(mlx);
			if (mlx->i == mlx->iter_max)
				fill_pixel(mlx->img_str, mlx->x, mlx->y, BLACK);
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
