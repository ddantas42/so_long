/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/30 15:18:40 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keypress_actions(int keycode, t_vars *vars)
{
	ft_printf("Key pressed = %d\n", keycode);
	if (keycode == ESCAPE)
	{
		ft_printf("Escape pressed!\nClosing program...\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
