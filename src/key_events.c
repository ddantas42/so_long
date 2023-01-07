/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/07 13:27:14 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window_cross(t_game *game)
{
	ft_printf("windown cross pressed!\nClosing program...\n");
	mlx_loop_end((game)->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress_count(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
	{
		ft_printf("Escape pressed!\nClosing program...\n");
		mlx_destroy_window(game->mlx, game->mlx_window);
		mlx_loop_end((game)->mlx);
		free(game->map);
		exit(EXIT_SUCCESS);
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