/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:09:05 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/12 17:46:41 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH	800
# define WIN_HEIGHT	800

# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500
# define BLACK 0x000000


typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

int	ft_key_events(int keycode, t_mlx *mlx);
int	mandelbrot(void);

#endif
