/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/13 19:09:11 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_c_up(t_game *game)
{
	int	n;

	n = 0;
	while (n < game->map_all_c)
	{
		if (!game->map_c_x[n] || !game->map_c_y[n])
		{
			n++;
			continue ;
		}
		if (game->map[game->map_c_y[n]][game->map_c_x[n]] == 'C')
		{
			mlx_put_image_to_window(
				game->mlx, game->mlx_window, game->collectiableup,
				game->map_c_x[n] * 32, game->map_c_y[n] * 32);
		}
		n++;
	}
	return (0);
}

int	put_c_mid(t_game *game)
{
	int	n;

	n = 0;
	while (n < game->map_all_c)
	{
		if (!game->map_c_x[n] || !game->map_c_y[n])
		{
			n++;
			continue ;
		}
		if (game->map[game->map_c_y[n]][game->map_c_x[n]] == 'C')
		{
			mlx_put_image_to_window(
				game->mlx, game->mlx_window, game->collectiable,
				game->map_c_x[n] * 32, game->map_c_y[n] * 32);
		}
		n++;
	}
	return (0);
}

int	put_c_down(t_game *game)
{
	int	n;

	n = 0;
	while (n < game->map_all_c)
	{
		if (!game->map_c_x[n] || !game->map_c_y[n])
		{
			n++;
			continue ;
		}
		if (game->map[game->map_c_y[n]][game->map_c_x[n]] == 'C')
		{
			mlx_put_image_to_window(
				game->mlx, game->mlx_window, game->collectiabledown,
				game->map_c_x[n] * 32, game->map_c_y[n] * 32);
		}
		n++;
	}
	return (0);
}

int	window_cross(t_game *game)
{
	ft_printf("windown cross pressed!\nClosing program...\n");
	mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_loop_end((game)->mlx);
	free_everything(game, 3);
	return (0);
}

int	keypress_count(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
	{
		ft_printf("Escape pressed!\nClosing program...\n");
		mlx_destroy_window(game->mlx, game->mlx_window);
		mlx_loop_end((game)->mlx);
		free_everything(game, 3);
	}
	if (keycode == ON_W)
		move_up(game);
	if (keycode == ON_A)
		move_left(game);
	if (keycode == ON_S)
		move_down(game);
	if (keycode == ON_D)
		move_right(game);
	return (0);
}
