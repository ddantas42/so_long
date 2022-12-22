# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 17:37:45 by ddantas-          #+#    #+#              #
#    Updated: 2022/12/22 19:17:43 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

FILESC = main.c #\

OBJS = $(FILESC:.c=.o)


LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
MINILIBX = ./mlx_linux/libmlx_Linux.a

# INC	= -I. -I./libft -I./ft_printf -Imlx_linux
INC		= -lXext -lX11

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX) $(INC)

$(LIBFT):
	make -C libft
	
$(FT_PRINTF):
	make -C ft_printf

$(MINILIBX): 
	make -C mlx_linux

%.o: %.c
	echo Here!
	$(CC) -Wall -Wextra -Werror -O3 -c -o $@ $<


clean:
	rm -f *.o
	make -C libft fclean
	make -C ft_printf fclean
	make -C mlx_linux clean
	
fclean: clean
	rm so_long

re: fclean all


.PHONY: all clean fclean re