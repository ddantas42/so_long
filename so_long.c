/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/06 17:10:12 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

void	free_everything(g_data *game)
{
	free(game);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	//t_data	mlx_img;
	g_data	game;
	i_data images;

	if (map_checker(argv[1], argc, &game) == 1)
	{
		free_everything(&game);
		return (0);
	}
	ft_printf("Map checked complete\ninitiating window...\n");
	game.mlx = mlx_init();

	if (game.x_window > 8160 || game.x_window < 32 || game.y_window < 32 || game.y_window > 8160)
	{
		ft_printf("CUIDADO COM O X OU Y!!!\nx = %d | y = %d\n", game.x_window, game.y_window);
		return (0);
	}

	ft_printf("x_window = %d | y_window = %d\n", game.x_window, game.y_window);
	game.mlx_window = mlx_new_window(game.mlx, game.x_window, game.y_window, "So_long :D");

	//TESTING AREA IMAGES
	
	assign_img(&game, &images);

	int x = 0; int y = 0; int n = 0;
	while (n < 8)
	{
		y = 0;
		while(y < game.y_window / 32)
		{
			x = 0;
			while (x < game.x_window / 32)
			{
				mlx_put_image_to_window(game.mlx, game.mlx_window, images.background, 32*x, 32*y);
				x++;
			}
			y++;
		}
		n++;
	}

	ft_printf("n = %d\n", n);

	//TESTING AREA IMAGES

	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

	ft_printf("Estou a funcionar!!! :D\n");


	mlx_hook(game.mlx_window, ON_KEYPRESS, KEYPRESSMASK, keypress_actions, &game);
	
	mlx_hook(game.mlx_window, ON_DESTROY, DESTROYMARSK, window_cross, &game);
	
	mlx_loop(game.mlx);
	return (0);
}