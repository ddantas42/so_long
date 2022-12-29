/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/29 18:10:11 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	erro(void)
{
	ft_printf("Error\n");
	return(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	int x_window;
	int y_window;

	(void)argc;

	if (map_checker(argv[1], argc) == 1)
		return (0);

	vars.mlx = mlx_init();

	x_window = 1000;
	y_window = 500;

	img.img = mlx_new_image(vars.mlx, x_window, y_window);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,&img.line_length,&img.endian);

	vars.mlx_win = mlx_new_window(vars.mlx, x_window, y_window, "So_long :D");

	
	/* TESTING ZONE START */
	int n = 0;int j = 0; int color; int r = 255; int g = 0; int b = 0; int loops = 1;
	while (n++ < x_window)
	{
		j = 0;
		color = create_trgb(100, r, g, b);
		if (loops == 1)
		{
			g++;
			if (g == 255)
				loops = 2;
		}
		if (loops == 2)
		{
			r--;
			if (r == 0)
				loops = 3;
		}
		if (loops == 3)
		{
			b++;
			if (b == 255)
				loops = 4;
		}
		if (loops == 4)
		{
			g--;
			if (g == 0)
				loops = 5;
		}
		if (loops == 5)
		{
			r++;
			if (r == 255)
				loops = 6;
		}
		if (loops == 6)
		{
			b--;
			if (b == 0)
				loops = 1;
		}
		while (j++ < y_window)
		{	
			my_mlx_pixel_put(&img, n, j, color);
		}
	}
	
	/* TESTING ZONE OVER */


	ft_printf("Estou a funcionar!!! :D\n");

	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_hook(vars.mlx_win, 2, (1L << 0), keypress_actions, &vars);

	mlx_loop(vars.mlx);
	return (0);
}
