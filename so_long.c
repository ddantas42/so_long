/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/27 22:34:22 by ddantas-         ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	
	vars.mlx = mlx_init();
	

	img.img = mlx_new_image(vars.mlx, 1000, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	
	vars.mlx_win = mlx_new_window(vars.mlx, 1000, 500, "So_long :D");

	
	/* TESTING ZONE START */
	int n = 0;int b = 0; int color;
	while (n++ < 500)
	{
		color = create_trgb(100, 255, 0, 0);
		b = 0;
		while (b++ < 500)
			my_mlx_pixel_put(&img, n, b, color);
	}
	
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	/* TESTING ZONE OVER */


	
	ft_printf("Estou a funcionar!!! :D\n");
	mlx_hook(vars.mlx_win, 2, (1L << 0), hook_actions, &vars);
	
	mlx_loop(vars.mlx);
	return (0);
}