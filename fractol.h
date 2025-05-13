/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 07:56:46 by eakyurek          #+#    #+#             */
/*   Updated: 2025/04/15 07:48:25 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

# define DEEP_SPACE      0x0D0D1A
# define SMOKY_PURPLE    0x5D3FD3
# define PLASMA_VIOLET   0x9467BD
# define DREAM_BLUE      0x3399FF
# define CLOUD_CYAN      0x66FFFF
# define PIXEL_TEAL      0x3CD3A3
# define HACKER_GREEN    0x00CC66
# define NANO_LIME       0xBFFF00
# define CHROME_YELLOW   0xFFD700
# define SUNSET_ORANGE   0xFF944D
# define NEON_CORAL      0xFF6F61
# define CYBERMAUVE      0xC71585
# define NIGHT_PINK      0xFF69B4
# define TERMINAL_GRAY   0x2C2F33
# define HORIZON_WHITE   0xDDE1E4

typedef struct s_map
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}			t_map;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*title;
	int		img_bpp;
	int		img_line;
	int		img_endian;
	int		iterations;
	int		color;
	double	compl_real;
	double	compl_i;
	double	hypotenuse;
	double	shift_real;
	double	shift_i;
	double	zoom;
	double	julia_real;
	double	julia_i;
}			t_fractal;

t_fractal	square_complex(t_fractal z);
t_fractal	sum_complex(t_fractal z1, t_fractal z2);
void		manual(void);
void		malloc_error(void);
void		fractol_init(t_fractal *fractal);
void		fractol_render(t_fractal *fractal);
void		zoom_in(t_fractal *fract, double mouse_real, double mouse_i);
void		zoom_out(t_fractal *fract, double mouse_real, double mouse_i);
void		color_shift(t_fractal *fractal);
int			blend_colors(int color1, int color2, double t);
int			handle_close(t_fractal *fractal);
int			keys(int keysym, t_fractal *fractal);
int			handle_mouse(int button, int x, int y, t_fractal *fractal);
double		ft_atod(char *s);
double		map(t_map coords);

#endif
