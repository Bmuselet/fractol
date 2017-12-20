/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:07:39 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/18 17:20:19 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mouse_zoom2(int button, t_mlx *mlx)
{
	if (button == 4)
	{
		mlx->zoom_x += mlx->zoom_x * 1.15;
		mlx->zoom_y += mlx->zoom_y * 1.15;
		mlx->x1 = mlx->tmp_x1 - (mlx->x2 - mlx->x1) / 4;
		mlx->y1 = mlx->tmp_y1 - (mlx->y2 - mlx->y1) / 4;
		mlx->x2 = mlx->tmp_x1 + (mlx->x2 - mlx->tmp_x2) / 4;
		mlx->y2 = mlx->tmp_y1 + (mlx->y2 - mlx->tmp_y2) / 4;
	}
	if (button == 5)
	{
		mlx->zoom_x -= mlx->zoom_x * 0.45;
		mlx->zoom_y -= mlx->zoom_y * 0.45;
	}
	return (0);
}

int			ft_mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x <= 0 || y <= 0)
		return (0);
	mlx->tmp_x1 = mlx->x1 + x * (mlx->x2 - mlx->x1) / WIN_WIDTH;
	mlx->tmp_y1 = mlx->y1 + y * (mlx->y2 - mlx->y1) / WIN_HEIGHT;
	mlx->tmp_x2 = mlx->x1;
	mlx->tmp_y2 = mlx->y1;
	ft_mouse_zoom2(button, mlx);
	ft_draw(mlx);
	return (0);
}

int			ft_move_julia(int x, int y, t_mlx *mlx)
{
	if (x <= WIN_WIDTH && y <= WIN_HEIGHT && x >= 0 && y >= 0
		&& mlx->num_f == 2 && mlx->lock == 0)
	{
		mlx->c_r = (double)x / (double)WIN_WIDTH * 4 - 2;
		mlx->c_i = (double)y / (double)WIN_HEIGHT * 4 - 2;
		ft_draw(mlx);
	}
	return (0);
}
