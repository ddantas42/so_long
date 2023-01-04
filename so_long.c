/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/04 08:05:47 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

void	free_everything(g_data *game)
{
	free(game);
	exit(EXIT_FAILURE);
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
	g_data	game;

	//(void)argc;
	//(void)argv;
	if (map_checker(argv[1], argc, &game) == 1)
		free_everything(&game);
	ft_printf("Map checked complete\ninitiating window...\n");

	game.y_window = 1080;
	//printf("X = %d\n",game.x_window);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, game.x_window, game.y_window, "So_long :D");

	//TESTING AREA IMAGES
	char *path;
	
	int real_x = 32; int real_y = 32;
	int *x_img; int *y_img;
	x_img = &real_x; y_img = &real_y;
	path = malloc(24);
	path = "./images/background.xpm";

	
	img.img = mlx_xpm_file_to_image(game.mlx, path, x_img, y_img);
	if (!img.img)
	{
		ft_printf("Reading of image failed!");
		return (0);
	}
	

	int x = 0; int y = 0;
	while (y < 135)
	{
		ft_printf("\ny = %d\n", y);
		x = 0;
		while (x < 240)
		{
			mlx_put_image_to_window(game.mlx, game.mlx_window, img.img, 32*x, 32*y);
			x++;
		}
		y++;
	}
	path = "./images/character.xpm";
	img.img = mlx_xpm_file_to_image(game.mlx, path, x_img, y_img);
	mlx_put_image_to_window(game.mlx, game.mlx_window, img.img, 32*100, 32*100);
	y = 0; x = 0;
	while (y < 135)
	{
		//ft_printf("\ny = %d\n", y);
		x = 0;
		while (x < 240)
		{
			mlx_put_image_to_window(game.mlx, game.mlx_window, img.img, 32*x, 32*y);
			x++;
		}
		y++;
	}

	//TESTING AREA IMAGES

	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

	ft_printf("Estou a funcionar!!! :D\n");


	mlx_hook(game.mlx_window, ON_KEYPRESS, KEYPRESSMASK, keypress_actions, &game);
	
	mlx_hook(game.mlx_window, ON_DESTROY, DESTROYMARSK, window_cross, &game);
	
	mlx_loop(game.mlx);
	return (0);
}