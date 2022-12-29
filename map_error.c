/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/29 18:02:58 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_closed(unsigned char **map, int lines)
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

int	map_empty(unsigned char **map)
{
	if (!map[0])
	{
		ft_printf("Error\nNo map found\n");
		return (0);
	}
	return (1);
}

int	map_checker(char *file, int argc)
{
	unsigned char	**map;
	int				n;
	int				fd;
	int				fd_new;

	if (argc != 2)
	{
		ft_printf("Error\ninsert only the map as a parameter!!\n");
		return (1);
	}
	fd = open(file, O_RDONLY);
	map = (unsigned char **)malloc(file_lengh(fd) + 1);
	if (!map)
	{
		ft_printf("Error\nMalloc allocation error\n");
		return (1);
	}
	fd_new = open(file, O_RDONLY);
	n = 0;
	map[n] = (unsigned char *)get_next_line(fd_new);
	while (map[n])
		map[++n] = (unsigned char *)get_next_line(fd_new);
	if (map_empty(map) && map_closed(map, n - 1) && map_square(map, n - 1))
		return (0);
	return (1);
}