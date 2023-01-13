/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/13 17:11:11 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_p_set(t_game *game, int line, int column)
{
	game->player_y = line;
	game->player_x = column;
	game->buffer = game->character;
	return (0);
}

void	img_c_set(t_game *game, int line, int column)
{
	static int	n = 0;


	game->map_c_y[n] = line;
	game->map_c_x[n++] = column;
	if (line && column)
		game->buffer = game->collectiable;
	game->map_all_c++;
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
				img_c_set(game, line, column);
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

	game->map_all_c = 0;
	game->map_c_x = (int *)malloc(255);
	game->map_c_y = (int *)malloc(255);
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
