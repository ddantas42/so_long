/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/13 21:58:49 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

int	next_frame_2(t_game *game, int *loop)
{
	if (game->frames < 30000)
	{
		if (*loop == 0)
			game->frames++;
		if (*loop == 1)
			game->frames--;
		return (0);
	}
	if (game->frames >= 22500)
	{
		*loop = 1;
		put_c_up(game);
		game->frames = 29999;
		return (0);
	}
	return (0);
}

int	next_frame(t_game *game)
{
	static int	loop = 0;

	if (game->frames < 15000)
	{
		if (loop)
			game->frames = 0;
		if (game->frames == 7500)
			put_c_down(game);
		loop = 0;
		game->frames++;
		return (0);
	}
	if (game->frames == 15000)
		put_c_mid(game);
	return (next_frame_2(game, &loop));
}

int	free_everything(t_game *game, int part)
{
	if (part >= 1)
		free(game->map);
	if (part >= 2)
	{
		free(game->mlx_window);
		free(game->mlx);
	}
	if (part >= 3)
		free(game->map_c_x);
	if (part >= 4)
		free(game->map_c_y);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map_collectiables = 0;
	game.p_moves = 0;
	game.frames = 15001;
	if (map_checker(argv[1], argc, &game) == 1)
		free_everything(&game, 1);
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
