/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:37:00 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/07 13:24:08 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define ESCAPE 65307
# define ON_W 119
# define ON_A 97
# define ON_S 115
# define ON_D 100

# define ON_KEYPRESS 2
# define ON_DESTROY 17

# define BACKGROUND "./images/background.xpm"
# define CHARACTER "./images/character.xpm"
# define COLLECTIABLE "./images/collectiable.xpm"
# define EXIT "./images/exit.xpm"
# define WALL "./images/wall.xpm"

typedef struct game_data {
	void			*mlx;
	void			*mlx_window;
	int				x_window;
	int				y_window;
	int				p_moves;
	unsigned char	**map;
	int				player_x;
	int				player_y;
	int				image_x;
	int				image_y;
	int				*ptr_x;
	int				*ptr_y;
	void			*background;
	void			*character;
	void			*collectiable;
	void			*exit;
	void			*wall;
	void			*buffer;
}				t_game;

typedef struct mlx_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*		key_events.c	*/
int		window_cross(t_game *game);
int		keypress_count(int keycode, t_game *game);

/*		map_error.c		*/
int		map_square(unsigned char **map, int lines);
int		map_closed(unsigned char **map, int lines);
int		map_closed_2(unsigned char **map, int l, int n);
int		map_cep(unsigned char **map, int lines);
int		map_checker(char *file, int argc, t_game *game);

/*		moves.c			*/
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

/*		so_long_utils.c		*/
int		file_lengh(int fd, t_game *game);
int		map_cep_2(unsigned char **map, int lines, int c, int e, int p, int i);
int		map_cep_error(int c, int e, int p, int invalid);
int		map_cep_error_2(int p, int invalid);

/*		vars_setup.c		*/
void	error_img(void);
int		img_p_set(t_game *game, int line, int column);
int		determine_cep(t_game *game);
void	draw_map(t_game *game);
void	assign_img(t_game *game);

#endif