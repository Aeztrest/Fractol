/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 07:57:53 by eakyurek          #+#    #+#             */
/*   Updated: 2025/04/15 07:51:56 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	fractol_set(t_fractal *z, t_fractal *c, t_fractal *fract)
{
	if (!ft_strncmp(fract->title, "Julia", 5))
	{
		c->compl_real = fract->julia_real;
		c->compl_i = fract->julia_i;
	}
	else
	{
		c->compl_real = z->compl_real;
		c->compl_i = z->compl_i;
		z->compl_real = 0;
		z->compl_i = 0;
	}
}

static void	ft_pixel_put(int x, int y, t_fractal *fract, int rgb)
{
	int	offset;

	offset = y * fract->img_line + x * (fract->img_bpp / 8);
	*(unsigned int *)(fract->addr + offset) = rgb;
}

static void	get_complex_map(int x, int y, t_fractal *fract)
{
	t_fractal	z;
	t_fractal	c;
	int			i;
	int			rgb;

	i = -1;
	z.compl_real = (map((t_map){x, -2, +2, 0, WIDTH})
			* fract->zoom) + fract->shift_real;
	z.compl_i = (map((t_map){y, +2, -2, 0, HEIGHT})
			* fract->zoom) + fract->shift_i;
	fractol_set(&z, &c, fract);
	while (++i < fract->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.compl_real * z.compl_real + z.compl_i
				* z.compl_i) > fract->hypotenuse)
		{
			rgb = blend_colors(DEEP_SPACE, fract->color,
					(double)i / fract->iterations);
			ft_pixel_put(x, y, fract, rgb);
			return ;
		}
	}
	ft_pixel_put(x, y, fract, DEEP_SPACE);
}

void	fractol_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			get_complex_map(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
