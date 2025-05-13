/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 07:56:02 by eakyurek          #+#    #+#             */
/*   Updated: 2025/04/15 07:09:28 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		manual();
		argv[1][0] = ft_toupper(argv[1][0]);
		fractal.title = argv[1];
		if (!ft_strncmp(fractal.title, "Julia", 15))
		{
			fractal.julia_real = ft_atod(argv[2]);
			fractal.julia_i = ft_atod(argv[3]);
		}
		fractol_init(&fractal);
		fractol_render(&fractal);
		mlx_loop(fractal.mlx);
		return (0);
	}
	ft_printf("Error: Invalid arguments\n");
	ft_printf("Usage: ./fractol <mandelbrot>\n\t or \t\n");
	ft_printf("./fractol <julia> <real> <imaginary>\n");
	exit(EXIT_FAILURE);
}
