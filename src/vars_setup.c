/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/06 17:13:41 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	error_img()
{
	ft_printf("Error\nImage error\n");
	exit(EXIT_FAILURE);
}

void	assign_img(g_data *game, i_data *images)
{
	images->image_x = 32;
	images->image_y = 32;
	images->ptr_x = &(images->image_x);
	images->ptr_y = &(images->image_y);
	images->background = mlx_xpm_file_to_image(game->mlx, BACKGROUND, images->ptr_x, images->ptr_y);
	images->character = mlx_xpm_file_to_image(game->mlx, CHARACTER, images->ptr_x, images->ptr_y);
	images->collectiable = mlx_xpm_file_to_image(game->mlx, COLLECTIABLE, images->ptr_x, images->ptr_y);
	images->exit = mlx_xpm_file_to_image(game->mlx, EXIT, images->ptr_x, images->ptr_y);
	images->wall = mlx_xpm_file_to_image(game->mlx, WALL, images->ptr_x, images->ptr_y);
}