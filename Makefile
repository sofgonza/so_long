# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 12:20:35 by sofgonza          #+#    #+#              #
#    Updated: 2023/08/05 16:35:53 by sofgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

RM = rm -f

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)
SRC = main.c map_check.c map_check_utils.c utils.c parce.c parce_utils.c
OBJS = $(SRC:.c=.o)

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(GNLOBJS)
	make -C ./libft
	make -C ./printf
	$(CC) $(CFLAGS) $(GNLOBJS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)

clean:
	$(RM) $(OBJS) $(GNLOBJS)
	make clean -C ./libft
	make clean -C ./printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
	make fclean -C ./printf

re: clean all

.PHONY: all clean fclean re
