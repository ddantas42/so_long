/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/03 16:45:02 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window_cross(g_data *game)
{
	ft_printf("windown cross pressed!\nClosing program...\n");
	mlx_loop_end((game)->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress_actions(int keycode, g_data *game)
{
	ft_printf("Key pressed = %d\n", keycode);
	if (keycode == ESCAPE)
	{
		ft_printf("Escape pressed!\nClosing program...\n");
		mlx_destroy_window(game->mlx, game->mlx_window);
		mlx_loop_end((game)->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
