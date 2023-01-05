/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/03 17:31:37 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	assign_img(g_data *game, i_data *images)
{
	char	*path_background;
	/*char	path_wall[18];
	char	path_character[23];
	char	path_exit[18];
	char	path_collectiable[26];*/

	images->image_x = 32;
	images->image_y = 32;

	images->ptr_image_x = &(images->image_x);
	images->ptr_image_y = &(images->image_y);
	
	path_background = (char *)malloc(24);
	if (!path_background)
	{
		ft_printf("Error\nErro memory allocation\n");
		return(0);
	}
	path_background = "./images/background.xpm";
	/*path_wall = "./images/wall.xpm";
	path_character = "./images/character.xpm";
	path_exit = "./images/exit.xpm";
	path_collectiable = "./images/collectiable.xpm";*/

	images->background = mlx_xpm_file_to_image(game->mlx, path_background, images->ptr_image_x, images->ptr_image_y);
	
	return (0);
}