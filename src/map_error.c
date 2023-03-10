/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/13 18:55:49 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_square(unsigned char **map, int lines)
{
	int	n;
	int	line_lengh;

	n = 0;
	line_lengh = ft_strlen((const char *)map[n]) - 1;
	if (line_lengh == lines)
	{
		ft_printf("Error\nMap bad format (Must be rectangular)\n");
		return (0);
	}
	while (map[n]
		&& line_lengh == (((int)(ft_strlen((const char *)map[n]))) - 1))
		n++;
	if (n == lines)
		n--;
	if (line_lengh == (((int)(ft_strlen((const char *)map[n])))))
		return (1);
	ft_printf("Error\nMap bad format (Must be rectangular)\n");
	return (0);
}

int	map_closed(unsigned char **map, int lines)
{
	int	len;
	int	n;
	int	l;

	len = ft_strlen((const char *)map[0]);
	l = 0;
	while (l <= 1)
	{	
		n = 0;
		while (n < len - 1)
		{
			if (l == 1)
				l = lines;
			if (map[l][n] != '1')
			{
				ft_printf("Error\nMap not surrounded by walls\n");
				return (0);
			}
			n++;
		}
		l++;
	}
	return (map_closed_2(map, l, n));
}

int	map_closed_2(unsigned char **map, int l, int n)
{
	l--;
	while (l >= 0)
	{
		if (map[l][0] != '1' || map[l][n - 1] != '1')
		{
			ft_printf("Error\nMap not surrounded by walls\n");
			return (0);
		}
		l--;
	}
	return (1);
}

int	map_cep(unsigned char **map, int lines, t_game *game)
{
	int	e;
	int	p;
	int	i;
	int	n;

	e = 0;
	p = 0;
	i = 0;
	while (lines-- >= 1)
	{
		n = 0;
		while (n < (int)ft_strlen((const char *)map[0]) - 1)
		{
			if (map[lines][n] == 'C')
				game->map_collectiables++;
			else if (map[lines][n] == 'E')
				e++;
			else if (map[lines][n] == 'P')
				p++;
			else if (map[lines][n] != '0' && map[lines][n] != '1')
				i++;
			n++;
		}	
	}
	return (map_cep_error(game->map_collectiables, e, p, i));
}

int	map_checker(char *file, int argc, t_game *game)
{
	int				n;
	int				fd;

	if (argc != 2)
	{
		ft_printf("Error\ninsert only the map as a parameter!!\n");
		free_everything(game, 1);
	}
	fd = open(file, O_RDONLY);
	game->map = (unsigned char **)malloc(file_lengh(fd, game) + 1);
	if (!game->map)
	{
		ft_printf("Error\nMalloc allocation error\n");
		free_everything(game, 1);
	}
	fd = open(file, O_RDONLY);
	n = 0;
	game->map[n] = (unsigned char *)get_next_line(fd);
	while (game->map[n])
		game->map[++n] = (unsigned char *)get_next_line(fd);
	game->y_window = 32 * n;
	if (map_square(game->map, n)
		&& map_closed(game->map, n - 1) && map_cep(game->map, n, game))
		return (0);
	return (free_everything(game, 1));
}
