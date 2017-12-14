/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:46:47 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/14 18:01:44 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	change_color(t_mlx *mlx)
{
	mlx->color_value += 1;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	julia(*mlx);
}

/*int			move_julia(t_mlx *mlx)
  {
  if (mlx->x >= WIN_WIDTH || mlx->y >= WIN_HEIGHT || mlx->x <= 0 || mlx->y <= 0)
  return (0);
  mlx->c_r = (mlx->x + (WIN_WIDTH / 2)) / (WIN_WIDTH * 2);
  mlx->c_i = (mlx->y + (WIN_HEIGHT / 2)) / (WIN_HEIGHT * 2);
  mlx_destroy_image(mlx->mlx, mlx->img);
  mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
  julia(*mlx);
  return (0);
  }*/

static void	ft_key_zoom(int keycode, t_mlx *mlx)
{
//	mlx->tmp_x = mlx->x1 + (WIN_WIDTH / 2) * (mlx->x2 - mlx->x1) / WIN_WIDTH;
//	mlx->tmp_y = mlx->y1 + (WIN_HEIGHT / 2) * (mlx->y2 - mlx->y1) / WIN_HEIGHT;
//	mlx->tmp_x2 = mlx->x1;
//	mlx->tmp_y2 = mlx->y1;
	if (keycode == 116)
	{
		mlx->zoom *= 1.1;
//		mlx->x1 = mlx->tmp_x - (mlx->x2 - mlx->x1) / 4;
//		mlx->x2 = mlx->tmp_x + (mlx->x2 - mlx->tmp_x2) / 4;
//		mlx->y1 = mlx->tmp_y - (mlx->y2 - mlx->y1) / 4;
//		mlx->y2 = mlx->tmp_y + (mlx->y2 - mlx->tmp_y2) / 4;
	}
	else if (keycode == 121)
	{
		mlx->zoom /= 1.1;
//		mlx->x1 = mlx->tmp_x - (mlx->x2 - mlx->x1);
//		mlx->x2 = mlx->tmp_x + (mlx->x2 - mlx->tmp_x2);
//		mlx->y1 = mlx->tmp_y - (mlx->y2 - mlx->y1);
//		mlx->y2 = mlx->tmp_y + (mlx->y2 - mlx->tmp_y2);
	}
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	julia(*mlx);
}

static void	escape(int keycode)
{
	if (keycode == 53)
		exit(1);
}

int			ft_key_events(int keycode, t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	printf("%d ", keycode);
	if (keycode == 116 || keycode == 121)
	{
		ft_key_zoom(keycode, mlx);
		x++;
		y++;
	}
	if (keycode == 53)
		escape(keycode);
//	if (keycode == 49)
//		move_julia(mlx);
	if (keycode == 8)
		change_color(mlx);
	return (0);
}
