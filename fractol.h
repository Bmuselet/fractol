/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:09:05 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/18 10:54:17 by bmuselet         ###   ########.fr       */
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

# define WIN_WIDTH	1200
# define WIN_HEIGHT	1200

# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500
# define BLACK 0x000000

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			s_l;
	int			endian;
	int			*img_str;
	int			num_f;
	int			i;
	int			x;
	int			y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		tmp_x1;
	double		tmp_y1;
	double		tmp_x2;
	double		tmp_y2;
	double		zoom_x;
	double		zoom_y;
	int			nb_zoom;
	int			image_x;
	int			image_y;
	int			iter_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	int			color_value;
	int			lock;
}				t_mlx;

int				ft_key_events(int keycode, t_mlx *mlx);
int				ft_draw_mandelbrot(t_mlx *mlx);
int				ft_draw_buddhabrot(t_mlx *mlx);
int				ft_draw_julia(t_mlx *mlx);
int				ft_draw_burning_ship(t_mlx *mlx);
void			fill_pixel(int *str, int x, int y, int color);
int				ft_mouse_events(int button, t_mlx *mlx);
unsigned int	get_color(int a, t_mlx *mlx);
void			ft_draw(t_mlx *mlx);
void			ft_init_mandelbrot(t_mlx *mlx);
void			ft_init_julia(t_mlx *mlx);
void			ft_init_buddhabrot(t_mlx *mlx);
void			ft_init_burning_ship(t_mlx *mlx);
void			ft_begin_frac(t_mlx *mlx);
int				ft_mouse_zoom(int button, int x, int y, t_mlx *mlx);
int				ft_move_julia(int x, int y, t_mlx *mlx);
int				ft_draw_spine(t_mlx *mlx);
void			ft_init_spine(t_mlx *mlx);
int				ft_expose_hook(t_mlx *mlx);

#endif
