/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:00 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/03 17:31:59 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define ESCAPE 65307

# define ON_KEYPRESS 2
# define KEYPRESSMASK (1L<<0)

# define ON_DESTROY 17
# define DESTROYMARSK (1L<<17)

# define ON_W 119
# define ON_A 97
# define ON_S 115
# define ON_D 100

typedef struct game_data {
	void	*mlx;
	void	*mlx_window;
	int		x_window;
	int		y_window;
}				g_data;

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
int	map_cep_error(int c, int e, int p, int invalid);
int	map_cep_error_2(int p, int invalid);

/*		key_events.c	*/
int	window_cross(g_data *game);
int	keypress_actions(int keycode, g_data *game);

/*		map_error.c		*/
int map_square(unsigned char **map, int lines);
int map_closed(unsigned char **map, int lines);
int map_closed_2(unsigned char **map, int l, int n);
int map_cep(unsigned char **map, int lines);
int	map_checker(char *file, int argc, g_data *game);

#endif