/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/08 22:44:31 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '1')
		return (0);
	if (game->map[game->player_y - 1][game->player_x] == 'C')
		c_check(game, ON_W);
	if (game->map[game->player_y - 1][game->player_x] == 'E')
	{
		if (e_check(game))
			return (0);
	}
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background,
		game->player_x * 32, game->player_y * 32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->characterup,
		(game->player_x * 32), (game->player_y * 32) - 32);
	game->player_y = game->player_y - 1;
	ft_printf("Moves made: %d W\n", ++game->p_moves);
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '1')
		return (0);
	if (game->map[game->player_y][game->player_x - 1] == 'C')
		c_check(game, ON_A);
	if (game->map[game->player_y][game->player_x - 1] == 'E')
	{
		if (e_check(game))
			return (0);
	}
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background,
		game->player_x * 32, game->player_y * 32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->characterleft,
		(game->player_x * 32) - 32, game->player_y * 32);
	game->player_x = game->player_x - 1;
	ft_printf("Moves made: %d A\n", ++game->p_moves);
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '1')
		return (0);
	if (game->map[game->player_y + 1][game->player_x] == 'C')
		c_check(game, ON_S);
	if (game->map[game->player_y + 1][game->player_x] == 'E')
	{
		if (e_check(game))
			return (0);
	}
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background,
		game->player_x * 32, game->player_y * 32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->characterdown,
		game->player_x * 32, (game->player_y * 32) + 32);
	game->player_y = game->player_y + 1;
	ft_printf("Moves made: %d S\n", ++game->p_moves);
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return (0);
	if (game->map[game->player_y][game->player_x + 1] == 'C')
		c_check(game, ON_D);
	if (game->map[game->player_y][game->player_x + 1] == 'E')
	{
		if (e_check(game))
			return (0);
	}
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->background,
		game->player_x * 32, game->player_y * 32);
	mlx_put_image_to_window(
		game->mlx, game->mlx_window, game->characterright,
		(game->player_x * 32) + 32, game->player_y * 32);
	game->player_x = game->player_x + 1;
	ft_printf("Moves made: %d D\n", ++game->p_moves);
	return (0);
}
