# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 14:32:31 by ddantas-          #+#    #+#              #
#    Updated: 2022/08/08 14:32:31 by ddantas-         ###   ########.fr        #		
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

FILESC = get_next_line.c \
		get_next_line_utils.c \

FILES0 = $(FILESC:.c=.o)

all: $(NAME)

$(NAME): $(FILES0)
	ar rc $(NAME) $(FILES0)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re