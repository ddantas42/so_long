# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 17:37:45 by ddantas-          #+#    #+#              #
#    Updated: 2022/12/22 22:04:35 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
RM = rm
FILESC = so_long.c \
		color.c

OBJS = $(FILESC:.c=.o)


LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
MINILIBX = ./mlx_linux/libmlx_Linux.a
INC		= -lXext -lX11

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX) $(INC)

$(LIBFT):
	$(MAKE) -C libft
	
$(FT_PRINTF):
	$(MAKE) -C ft_printf

$(MINILIBX): 
	$(MAKE) -C mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c -o $@ $<


clean:
	$(RM) -f *.o
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C mlx_linux clean
	
fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re