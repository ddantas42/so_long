/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/07 14:34:18 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

void	free_everything(t_game *game)
{
	free(game);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	//t_data	mlx_img;
	t_game	game;

	game.map_collectiables = 0;
	if (map_checker(argv[1], argc, &game) == 1)
		free_everything(&game);
	ft_printf("Map checked complete\ninitiating window...\n");
	game.mlx = mlx_init();
	if (game.x_window > 8160 || game.x_window < 32 || game.y_window < 32 || game.y_window > 8160)
	{
		ft_printf("CUIDADO COM O X OU Y!!!\nx = %d | y = %d\n", game.x_window, game.y_window);
		return (0);
	}
	ft_printf("x_window = %d | y_window = %d\n", game.x_window, game.y_window);
	game.mlx_window = mlx_new_window(game.mlx, game.x_window, game.y_window, "So_long :D");
	assign_img(&game);
	ft_printf("Estou a funcionar!!! :D\n");
	game.p_moves = 0;
	mlx_hook(game.mlx_window, ON_KEYPRESS, 1L<<0, keypress_count, &game);
	mlx_hook(game.mlx_window, ON_DESTROY, 1L<<17, window_cross, &game);
	mlx_loop(game.mlx);
	return (0);
}