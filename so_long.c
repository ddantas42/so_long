/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/22 17:24:01 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	void	*mlx;
	void	*img;
	
	(void)argc;
	(void)argv;
	mlx = mlx_init();
	img = mlx_new_window(mlx, 1920, 1080, "Hello not world");
	mlx_loop(mlx);
	ft_printf("Estou a funcionar!!! :D\n");
	return (0);
}