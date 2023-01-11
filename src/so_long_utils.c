/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/11 22:44:36 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_check(t_game *game, int keycode)
{
	if (keycode == ON_W)
		game->map[game->player_y - 1][game->player_x] = '0';
	if (keycode == ON_A)
		game->map[game->player_y][game->player_x - 1] = '0';
	if (keycode == ON_S)
		game->map[game->player_y + 1][game->player_x] = '0';
	if (keycode == ON_D)
		game->map[game->player_y][game->player_x + 1] = '0';
	ft_printf("Collectiables left: %d\n", --game->map_collectiables);
	return (0);
}

int	e_check(t_game *game)
{
	if (game->map_collectiables == 0)
	{
		ft_printf("Congrats! you made %d moves!\n", ++game->p_moves);
		free(game->map);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	file_lengh(int fd, t_game *game)
{
	int				len;
	unsigned char	*temp;

	temp = (unsigned char *)malloc(255);
	temp = temp_treat(temp, fd);
	len = 0;
	while (temp)
	{
		if (len == 0)
			game->x_window = (ft_strlen((const char *)temp) - 1) * 32;
		len += ft_strlen((const char *)temp);
		temp = (unsigned char *)get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (len);
}

int	map_cep_error(int c, int e, int p, int invalid)
{
	if (c < 1)
	{
		ft_printf("Error\nMap must have at least 1 collectiable");
		ft_printf("(map has %d)\n", c);
		return (0);
	}
	if (e != 1)
	{
		if (e > 1)
			ft_printf("Error\nMap must have only 1 exit (map has %d)\n", e);
		if (e == 0)
			ft_printf("Error\nMap must have exit (map has %d)\n", e);
		return (0);
	}
	return (map_cep_error_2(p, invalid));
}

int	map_cep_error_2(int p, int invalid)
{
	if (p != 1)
	{
		if (p > 1)
		{
			ft_printf("Error\nMap must have only 1 Player's starting position");
			ft_printf("(map has %d)\n", p);
		}
		if (p == 0)
		{
			ft_printf("Error\nMap must have 1 Player's starting position");
			ft_printf("(map has %d)\n", p);
		}
		return (0);
	}
	if (invalid != 0)
	{
		ft_printf("Error\nMap has %d invalid characters\n", invalid);
		return (0);
	}
	return (1);
}
