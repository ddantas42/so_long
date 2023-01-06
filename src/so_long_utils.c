/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/06 16:39:35 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_lengh(int fd, t_game *game)
{
	int				len;
	unsigned char	*temp;

	temp = (unsigned char *)malloc(255);
	if (!temp)
	{
		ft_printf("Error\nMalloc allocation");
		exit(EXIT_FAILURE);
	}
	temp = (unsigned char *)get_next_line(fd);
	if (!temp || ft_strlen((const char *)temp) == 0)
	{
		ft_printf("Error\nFile empty or not found\n");
		exit(EXIT_FAILURE);
	}
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

int	map_cep_2(unsigned char **map, int lines, int c, int e, int p, int i)
{
	int	n;

	while (lines >= 0)
	{
		n = 0;
		while (n < (int)ft_strlen((const char *)map[0]) - 1)
		{
			if (map[lines][n] == 'C')
				c++;
			else if (map[lines][n] == 'E')
				e++;
			else if (map[lines][n] == 'P')
				p++;
			else if (map[lines][n] != '0' && map[lines][n] != '1')
				i++;
			n++;
		}	
		lines--;
	}
	return (map_cep_error(c, e, p, i));
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