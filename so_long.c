/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/11 23:33:07 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

int	next_frame(t_game *game)
{
	static int loop = 1;

	//if (game->frames % 10000 == 0)
	//	ft_printf("game->frames = %d\n", game->frames);
	if (game->frames < 30000)
	{
		if (loop)
			game->frames = 0;
		if (game->frames == 15000)
			ft_printf("Put Collectiable low\n");
		loop = 0;
		game->frames++;
		return (0);
	}
	if (game->frames == 30000)
			ft_printf("Put Collectiable mid\n");
	if (game->frames < 60000)
	{
		if (loop == 0)
			game->frames++;
		if (loop == 1)
			game->frames--;
		return (0);
	}
	if (game->frames >= 45000)
	{
		loop = 1;
		ft_printf("Put Collectiable high\n");
		game->frames = 59999;
		return (0);
	}
	return (0);
}


void	free_everything(t_game *game)
{
	free(game);
	free(game->map);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map_collectiables = 0;
	game.p_moves = 0;
	game.frames = 30001;
	if (map_checker(argv[1], argc, &game) == 1)
		free_everything(&game);
	ft_printf("Map checked complete\ninitiating window...\n");
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(
			game.mlx, game.x_window, game.y_window, "So_long :D");
	assign_img(&game);
	mlx_loop_hook(game.mlx, next_frame, &game);
	mlx_hook(game.mlx_window, ON_KEYPRESS, 1L << 0, keypress_count, &game);
	mlx_hook(game.mlx_window, ON_DESTROY, 1L << 17, window_cross, &game);
	mlx_loop(game.mlx);
	return (0);
}
