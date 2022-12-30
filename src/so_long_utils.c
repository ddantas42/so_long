/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:20 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/30 14:54:21 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_lengh(int fd)
{
	int len;
	unsigned char *temp;
	
	temp = (unsigned char *)malloc(255);
	temp = (unsigned char *)get_next_line(fd);
	len = 0;
	while (temp)
	{
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
		ft_printf("Error\nMap must have at least 1 collectiable (map has %d)\n", c);
		return(0);
	}
	if (e != 1)
	{
		ft_printf("Error\nMap must have only 1 exit (map has %d)\n", e);
		return(0);
	}
	if (p != 1)
	{
		if (p > 1)
			ft_printf("Error\nMap must have only 1 Player's starting position(map has %d)\n", 1);
		if (p == 0)
			ft_printf("Error\nMap must have 1 Player's starting position\n");
		return(0);
	}
	if (invalid != 0)
	{
		ft_printf("Error\nMap has invalid characters\n");
		return(0);
	}
	return (1);
}