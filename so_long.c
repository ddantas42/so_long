/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/08 23:38:23 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

void	free_everything(t_game *game)
{
	free(game);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map_collectiables = 0;
	game.p_moves = 0;
	if (map_checker(argv[1], argc, &game) == 1)
		free_everything(&game);
	ft_printf("Map checked complete\ninitiating window...\n");
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(
			game.mlx, game.x_window, game.y_window, "So_long :D");
	assign_img(&game);
	mlx_hook(game.mlx_window, ON_KEYPRESS, 1L << 0, keypress_count, &game);
	mlx_hook(game.mlx_window, ON_DESTROY, 1L << 17, window_cross, &game);
	mlx_loop(game.mlx);
	return (0);
}
