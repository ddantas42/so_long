/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/30 16:04:59 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_square(unsigned char **map, int lines)
{
	int	n;
	int	line_lengh;

	n = 0;
	line_lengh = ft_strlen((const char *)map[n]) - 1;
	if (line_lengh == lines)
	{
		ft_printf("Error\nMap bad1 format (Must be rectangular)\n");	
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
		ft_printf("Error\nEmpty map\n");
		return (0);
	}
	return (1);
}

int map_cep(unsigned char **map, int lines)
{
	int	c;
	int	e;
	int	p;
	int invalid;
	int line_lengh;
	int n;
	
	c = 0;
	e = 0;
	p = 0;
	invalid = 0;
	line_lengh = ft_strlen((const char *)map[0]) - 1;
	while (lines >= 0)
	{
		n = 0;
		while (n < line_lengh)
		{
			if (map[lines][n] == 'C')
				c++;
			else if (map[lines][n] == 'E')
				e++;
			else if (map[lines][n] == 'P')
				p++;
			else if (map[lines][n] != '0' && map[lines][n] != '1')
				invalid++;
			n++;
		}	
		lines--;
	}
	return(map_cep_error(c, e, p, invalid));
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
	if (map_empty(map) && map_square(map, n) && map_closed(map, n - 1) && map_cep(map,n - 1))
		return (0);
	return (1);
}