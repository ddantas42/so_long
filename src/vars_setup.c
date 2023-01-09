
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:24:16 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/08 22:24:16 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_img(int code)
{
	if (code)
		ft_printf("Error\nImage error code: %d\n", code);
	else
		ft_printf("Error\nImage error, no code");
	exit(EXIT_FAILURE);
}

void	assign_sprites_c(t_game *game)
{
	game->character = mlx_xpm_file_to_image(
			game->mlx, CHARACTER, game->ptr_x, game->ptr_y);
	if (!game->character)
		error_img(4);
	game->characterup = mlx_xpm_file_to_image(
			game->mlx, CHARACTER_UP, game->ptr_x, game->ptr_y);
	if (!game->characterup)
		error_img(5);
	game->characterleft = mlx_xpm_file_to_image(
			game->mlx, CHARACTER_LEFT, game->ptr_x, game->ptr_y);
	if (!game->characterleft)
		error_img(6);
	game->characterdown = mlx_xpm_file_to_image(
			game->mlx, CHARACTER_DOWN, game->ptr_x, game->ptr_y);
	if (!game->characterdown)
		error_img(7);
	game->characterright = mlx_xpm_file_to_image(
			game->mlx, CHARACTER_RIGHT, game->ptr_x, game->ptr_y);
	if (!game->characterright)
		error_img(8);
	game->collectiable = mlx_xpm_file_to_image(
			game->mlx, COLLECTIABLE, game->ptr_x, game->ptr_y);
	if (!game->collectiable)
		error_img(9);
	draw_map(game);
}


void	assign_img(t_game *game)
{
	game->image_x = 32;
	game->image_y = 32;
	game->ptr_x = &(game->image_x);
	game->ptr_y = &(game->image_y);
	game->background = mlx_xpm_file_to_image(
			game->mlx, BACKGROUND, game->ptr_x, game->ptr_y);
	if (!game->background)
		error_img(1);
	game->exit = mlx_xpm_file_to_image(
			game->mlx, EXIT, game->ptr_x, game->ptr_y);
	if (!game->exit)
		error_img(2);
	game->wall = mlx_xpm_file_to_image(
			game->mlx, WALL, game->ptr_x, game->ptr_y);
	if (!game->wall)
		error_img(3);
	assign_sprites_c(game);
}