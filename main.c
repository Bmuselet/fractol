/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:05:17 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/13 12:32:23 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img_str = (int *)mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.s_l), &(mlx.endian));
	if (ac != 2)
	{
		ft_putstr("Usage : ./fractol <source.file>\n");
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mandelbrot(mlx);
	if (ft_strcmp(av[1], "julia") == 0)
		julia(mlx);
	if (ft_strcmp(av[1], "buddhabrot") == 0)
		buddhabrot(mlx);
	else
		ft_putstr("This fractale does not exist ... yet !!\nExisting file :\nmandelbrot\njulia\nbuddhabrot\n");
	return (0);
}
