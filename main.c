/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:05:17 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/19 15:37:05 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_expose_hook(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 27;
	y = 34;
	while (x <= 360)
		mlx_pixel_put(mlx->mlx, mlx->win, x++, y, WHITE);
	while (y <= 200)
		mlx_pixel_put(mlx->mlx, mlx->win, x, y++, WHITE);
	while (x >= 27)
		mlx_pixel_put(mlx->mlx, mlx->win, x--, y, WHITE);
	while (y >= 34)
		mlx_pixel_put(mlx->mlx, mlx->win, x, y--, WHITE);
	mlx_string_put(mlx->mlx, mlx->win, 35, 35, WHITE, "Quit = ESC");
	mlx_string_put(mlx->mlx, mlx->win, 35, 55, WHITE, "Move = ^ v < >");
	mlx_string_put(mlx->mlx, mlx->win, 35, 75, WHITE, "Zoom = PageUp PageDown or Scroll");
	mlx_string_put(mlx->mlx, mlx->win, 35, 95, WHITE, "Change color = c");
	mlx_string_put(mlx->mlx, mlx->win, 35, 115, WHITE, "Change fractal = TAB");
	mlx_string_put(mlx->mlx, mlx->win, 35, 135, WHITE, "Reset = Backspace");
	mlx_string_put(mlx->mlx, mlx->win, 35, 155, WHITE, "More/Less iterations = +/-");
	mlx_string_put(mlx->mlx, mlx->win, 35, 175, WHITE, "De/lock Julia = Space");
	return (0);
}

void		ft_draw(t_mlx *mlx)
{
	if (mlx->num_f == 1)
		ft_draw_mandelbrot(mlx);
	else if (mlx->num_f == 2)
		ft_draw_julia(mlx);
	else if (mlx->num_f == 3)
		ft_draw_buddhabrot(mlx);
	else if (mlx->num_f == 4)
		ft_draw_burning_ship(mlx);
	else if (mlx->num_f == 5)
		ft_draw_spine(mlx);
	ft_expose_hook(mlx);
}

void		ft_begin_frac(t_mlx *mlx)
{
	if (mlx->num_f == 1)
		ft_init_mandelbrot(mlx);
	else if (mlx->num_f == 2)
		ft_init_julia(mlx);
	else if (mlx->num_f == 3)
		ft_init_buddhabrot(mlx);
	else if (mlx->num_f == 4)
		ft_init_burning_ship(mlx);
	else if (mlx->num_f == 5)
		ft_init_spine(mlx);
	ft_draw(mlx);
}

static int	ft_check_error(char **av, t_mlx *mlx)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mlx->num_f = 1;
	if (ft_strcmp(av[1], "julia") == 0)
		mlx->num_f = 2;
	if (ft_strcmp(av[1], "buddhabrot") == 0)
		mlx->num_f = 3;
	if (ft_strcmp(av[1], "burning_ship") == 0)
		mlx->num_f = 4;
	if (ft_strcmp(av[1], "spine") == 0)
		mlx->num_f = 5;
	if (mlx->num_f == -1)
	{
		ft_putstr(
			"Existing file:\nmandelbrot\njulia\nbuddhabrot\n");
		ft_putstr("burning_ship\nspine\n");
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.num_f = -1;
	mlx.color_value = 1;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol 42");
	mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img_str = (int *)mlx_get_data_addr(mlx.img,
		&(mlx.bpp), &(mlx.s_l), &(mlx.endian));
	if (ac != 2)
	{
		ft_putstr("Usage : ./fractol <source.file>\n");
		return (0);
	}
	if (ft_check_error(av, &mlx) == 1)
		return (0);
	else
		ft_begin_frac(&mlx);
	ft_expose_hook(&mlx);
	mlx_hook(mlx.win, 4, 1L << 12, ft_mouse_zoom, &mlx);
	mlx_hook(mlx.win, 6, 1L << 6, ft_move_julia, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, ft_key_events, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
