/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:07:39 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/14 15:05:31 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	ft_mouse_zoom(int button, t_mlx *mlx)
{
	if (button == 4)
		mlx->zoom *= 1.1;
	if (button == 5 && mlx->zoom > 0.1)
		mlx->zoom /= 1.1;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	julia(*mlx);
}

int			ft_mouse_events(int button, t_mlx *mlx)
{
	printf("%d ", button);
	if (button == 4 || button == 5)
		ft_mouse_zoom(button, mlx);
	return (0);
}
