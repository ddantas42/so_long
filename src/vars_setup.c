/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/06 18:56:51 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_img(void)
{
	ft_printf("Error\nImage error\n");
	exit(EXIT_FAILURE);
}

int	determine_cep(t_game *game, t_img *images)
{
	static int	line = 0;
	static int	column = 0;

	while (line < (game->y_window / 32) - 1)
	{
		if (column < (game->x_window / 32))
		{
			if (game->map[line][column] == '0')
				images->buffer = images->background;
			if (game->map[line][column] == 'P')
				images->buffer = images->character;
			if (game->map[line][column] == 'C')
				images->buffer = images->collectiable;
			if (game->map[line][column] == 'E')
				images->buffer = images->exit;
			if (game->map[line][column] == '1')
				images->buffer = images->wall;
			column++;
			return (0);
		}
		column = 0;
		line++;
	}
	line = 0;
	return (0);
}

void	draw_map(t_game *game, t_img *images)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y_window / 32)
	{
		x = 0;
		while (x < game->x_window / 32)
		{
			determine_cep(game, images);
			mlx_put_image_to_window(
				game->mlx, game->mlx_window, images->buffer, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	assign_img(t_game *game, t_img *images)
{
	images->image_x = 32;
	images->image_y = 32;
	images->ptr_x = &(images->image_x);
	images->ptr_y = &(images->image_y);
	images->background = mlx_xpm_file_to_image(
			game->mlx, BACKGROUND, images->ptr_x, images->ptr_y);
	if (!images->background)
		error_img();
	images->character = mlx_xpm_file_to_image(
			game->mlx, CHARACTER, images->ptr_x, images->ptr_y);
	if (!images->character)
		error_img();
	images->collectiable = mlx_xpm_file_to_image(
			game->mlx, COLLECTIABLE, images->ptr_x, images->ptr_y);
	if (!images->collectiable)
		error_img();
	images->exit = mlx_xpm_file_to_image(
			game->mlx, EXIT, images->ptr_x, images->ptr_y);
	if (!images->exit)
		error_img();
	images->wall = mlx_xpm_file_to_image(
			game->mlx, WALL, images->ptr_x, images->ptr_y);
	if (!images->wall)
		error_img();
	draw_map(game, images);
}
