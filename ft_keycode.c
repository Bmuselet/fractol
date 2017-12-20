/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:46:47 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/19 10:55:39 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_fractal_or_color(int keycode, t_mlx *mlx)
{
	if (keycode == 48)
	{
		if (mlx->num_f < 5)
			mlx->num_f += 1;
		else
			mlx->num_f = 1;
		ft_begin_frac(mlx);
	}
	if (keycode == 8)
	{
		mlx->color_value += 1;
		ft_draw(mlx);
	}
}

static void	move_fractal(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
		mlx->x1 -= 350 / mlx->zoom_x;
	if (keycode == 124)
		mlx->x1 += 350 / mlx->zoom_x;
	if (keycode == 126)
		mlx->y1 -= 350 / mlx->zoom_x;
	if (keycode == 125)
		mlx->y1 += 350 / mlx->zoom_x;
	ft_draw(mlx);
}

static void	lock_reset_escape(int keycode, t_mlx *mlx)
{
	if (keycode == 49)
	{
		if (mlx->lock == 1)
			mlx->lock = 0;
		else
			mlx->lock = 1;
	}
	if (keycode == 51)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
		ft_begin_frac(mlx);
	}
	if (keycode == 53)
		exit(1);
}

static void	ft_key_zoom(int keycode, t_mlx *mlx)
{
	if (keycode == 24)
		mlx->iter_max += 50;
	if (keycode == 27 && mlx->iter_max >= 100)
		mlx->iter_max -= 50;
	if (keycode == 116)
	{
		mlx->zoom_x += mlx->zoom_x * 1.05 / 2;
		mlx->zoom_y += mlx->zoom_y * 1.05 / 2;
	}
	else if (keycode == 121)
	{
		mlx->zoom_x -= mlx->zoom_x * 0.5 / 2;
		mlx->zoom_y -= mlx->zoom_y * 0.5 / 2;
	}
	ft_draw(mlx);
}

int			ft_key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 116 || keycode == 121 || keycode == 24 || keycode == 27)
		ft_key_zoom(keycode, mlx);
	if (keycode == 53 || keycode == 51 || keycode == 49)
		lock_reset_escape(keycode, mlx);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move_fractal(keycode, mlx);
	if (keycode == 48 || keycode == 8)
		change_fractal_or_color(keycode, mlx);
	return (0);
}
