/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/07 13:31:07 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '1')
		return (0);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background, game->player_x*32, game->player_y*32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->character, (game->player_x*32), (game->player_y*32) - 32);
	game->player_y = game->player_y - 1;

	ft_printf("Moves made: %d W\n", ++game->p_moves);
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '1')
		return (0);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background, game->player_x*32, game->player_y*32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->character, (game->player_x*32) - 32, (game->player_y*32));
	game->player_x = game->player_x - 1;

	ft_printf("Moves made: %d A\n", ++game->p_moves);
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '1')
		return (0);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background, game->player_x*32, game->player_y*32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->character, (game->player_x*32), (game->player_y*32) + 32);
	game->player_y = game->player_y + 1;

	ft_printf("Moves made: %d S\n", ++game->p_moves);
	return (0);
}


int	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return (0);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background, game->player_x*32, game->player_y*32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->character, (game->player_x*32) + 32, game->player_y*32);
	game->player_x = game->player_x + 1;

	ft_printf("Moves made: %d D\n", ++game->p_moves);
	return (0);
}