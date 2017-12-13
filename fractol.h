/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:09:05 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/13 12:29:21 by bmuselet         ###   ########.fr       */
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

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					s_l;
	int					endian;
	int					*img_str;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom;
	int					iter_max;
	double				image_x;
	double				image_y;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				tmp;
}						t_mlx;

int						ft_key_events(int keycode);
int						mandelbrot(t_mlx mlx);
int						buddhabrot(t_mlx mlx);
int						julia(t_mlx mlx);
void					fill_pixel(int *str, int x, int y, int color);

#endif
