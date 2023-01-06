/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/06 19:09:40 by ddantas-         ###   ########.fr       */
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

int	keypress_actions_2(int keycode, t_game *game)
{
	if (keycode == ON_S)
	{
		game->p_moves++;
		ft_printf("Moves made: %d\n", game->p_moves);
	}
	if (keycode == ON_D)
	{
		game->p_moves++;
		ft_printf("Moves made: %d\n", game->p_moves);
	}
	return (0);
}

int	keypress_actions(int keycode, t_game *game)
{
	ft_printf("Key pressed = %d\n", keycode);
	if (keycode == ESCAPE)
	{
		ft_printf("Escape pressed!\nClosing program...\n");
		mlx_destroy_window(game->mlx, game->mlx_window);
		mlx_loop_end((game)->mlx);
		free(game->map);
		exit(EXIT_SUCCESS);
	}
	if (keycode == ON_W)
	{
		game->p_moves++;
		ft_printf("Moves made: %d\n", game->p_moves);
	}
	if (keycode == ON_A)
	{
		game->p_moves++;
		ft_printf("Moves made: %d\n", game->p_moves);
	}		
	keypress_actions_2(keycode, game);
	return (0);
}
