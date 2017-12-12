/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:05:17 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/12 18:01:46 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Usage : ./fractol <source.file>\n");
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mandelbrot();
	else
		ft_putstr("This fractal does not exist ... yet\n");
	return (0);
}