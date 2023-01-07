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

int	img_p_set(t_game *game, int line, int column)
{
	game->player_y = line;
	game->player_x = column;
	game->buffer = game->character;
	return (0);
}


int	determine_cep(t_game *game)
{
	static int	line = 0;
	static int	column = 0;

	while (line < (game->y_window / 32) - 1)
	{
		if (column < (game->x_window / 32))
		{
			if (game->map[line][column] == '0')
				game->buffer = game->background;
			if (game->map[line][column] == 'P')
				img_p_set(game, line, column);
			if (game->map[line][column] == 'C')
				game->buffer = game->collectiable;
			if (game->map[line][column] == 'E')
				game->buffer = game->exit;
			if (game->map[line][column] == '1')
				game->buffer = game->wall;
			column++;
			return (0);
		}
		column = 0;
		line++;
	}
	line = 0;
	return (0);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y_window / 32)
	{
		x = 0;
		while (x < game->x_window / 32)
		{
			determine_cep(game);
			mlx_put_image_to_window(
				game->mlx, game->mlx_window, game->buffer, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	assign_img(t_game *game)
{
	game->image_x = 32;
	game->image_y = 32;
	game->ptr_x = &(game->image_x);
	game->ptr_y = &(game->image_y);
	game->background = mlx_xpm_file_to_image(
			game->mlx, BACKGROUND, game->ptr_x, game->ptr_y);
	if (!game->background)
		error_img();
	game->character = mlx_xpm_file_to_image(
			game->mlx, CHARACTER, game->ptr_x, game->ptr_y);
	if (!game->character)
		error_img();
	game->collectiable = mlx_xpm_file_to_image(
			game->mlx, COLLECTIABLE, game->ptr_x, game->ptr_y);
	if (!game->collectiable)
		error_img();
	game->exit = mlx_xpm_file_to_image(
			game->mlx, EXIT, game->ptr_x, game->ptr_y);
	if (!game->exit)
		error_img();
	game->wall = mlx_xpm_file_to_image(
			game->mlx, WALL, game->ptr_x, game->ptr_y);
	if (!game->wall)
		error_img();
	draw_map(game);
}
