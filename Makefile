# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 17:37:45 by ddantas-          #+#    #+#              #
#    Updated: 2022/12/22 17:22:27 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

FILESC = so_long.c \

OBJ = $(FILESC:.c=.o)


LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
MINILIBX = ./mlx_linux/libmlx_Linux.a

INC	= -I. -I./libft -I./ft_printf -Imlx_linux

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(OBJ) so_long.c
	$(CC) $(CFLAGS) $(FILESC) $(LIBFT) $(FT_PRINTF) $(INC) -o $(NAME)

$(LIBFT):
	make -C libft
	
$(FT_PRINTF):
	make -C ft_printf

$(MINILIBX): 
	make -C mlx_linux

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include $(INC) -O3 -c $< -o $@


clean:
	rm -f *.o
	make -C libft fclean
	make -C ft_printf fclean
	make -C mlx_linux clean
	
fclean: clean
	rm so_long

re: fclean all


.PHONY: all clean fclean re