/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:00 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/29 18:12:03 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define ESCAPE 65307

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
}				t_vars;


typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


/*		color.c		*/
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

/*		so_long_utils.c		*/
int	file_lengh(int fd);


/*		key_events.c	*/
int	keypress_actions(int keycode, t_vars *vars);

/*		map_error.c		*/
int map_closed(unsigned char **map, int lines);
int map_square(unsigned char **map, int lines);
int	map_empty(unsigned char **map);
int	map_checker(char *file, int argc);

#endif
