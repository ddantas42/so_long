# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 17:37:45 by ddantas-          #+#    #+#              #
#    Updated: 2023/01/08 22:38:59 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror # -fsanitize=address para checkar leaks
NAME = so_long
RM = rm

FILESC = so_long.c \
		./src/key_events.c \
		./src/map_error.c \
		./src/map_setup.c \
		./src/moves.c \
		./src/so_long_utils.c \
		./src/vars_setup.c

OBJS = $(FILESC:.c=.o)


LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
MINILIBX = ./mlx_linux/libmlx_Linux.a
GETNEXTLINE = ./get_next_line/get_next_line.a
INC		= -lXext -lX11


all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(GETNEXTLINE) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) $(LIBFT) $(GETNEXTLINE) $(MINILIBX) $(INC)

$(LIBFT):
	$(MAKE) -C libft
	
$(FT_PRINTF):
	$(MAKE) -C ft_printf

$(MINILIBX): 
	$(MAKE) -C mlx_linux

$(GETNEXTLINE):
	$(MAKE) -C get_next_line

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c -o $@ $<

clean:
	$(RM) -f $(NAME).o
	$(RM) -f ./src/*.o
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C get_next_line fclean
	$(MAKE) -C mlx_linux clean
	
fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re