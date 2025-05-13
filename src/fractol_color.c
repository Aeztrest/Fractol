/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 07:57:35 by eakyurek          #+#    #+#             */
/*   Updated: 2025/04/15 07:47:51 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	blend_colors(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((color1 >> 16) & 0xFF) + t * ((color2 >> 16) & 0xFF)
			* 3);
	g = (int)((1 - t) * ((color1 >> 8) & 0xFF) + t * ((color2 >> 8) & 0xFF)
			* 3);
	b = (int)((1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF) * 3);
	r = (int)(r + (255 - r) * t * 2);
	g = (int)(g + (255 - g) * t * 0.1);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}

void	color_shift(t_fractal *fractal)
{
	static int	my_palette[] = {DEEP_SPACE, DREAM_BLUE, SMOKY_PURPLE,
		PLASMA_VIOLET, CLOUD_CYAN, PIXEL_TEAL, HACKER_GREEN, NANO_LIME,
		CHROME_YELLOW, SUNSET_ORANGE, NEON_CORAL, CYBERMAUVE, NIGHT_PINK,
		TERMINAL_GRAY, HORIZON_WHITE};
	static int	color_index;

	color_index = (color_index + 1) % (sizeof(my_palette)
			/ sizeof(my_palette[0]));
	fractal->color = my_palette[color_index];
	fractol_render(fractal);
}
