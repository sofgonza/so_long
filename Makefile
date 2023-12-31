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
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
MLX = ./mlx/libmlx.a
LIB = ./includes/so_long.h
SRC_PATH = ./src/

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)

SRC = so_long.c \
		map_check.c \
		map_check_utils.c \
		so_long_utils.c \
		parce.c \
		parce_utils.c \
		print_map.c \
		init_xpm.c \
		key_hooks.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(SRCS:.c=.o)

all: make_libft make_printf make_mlx $(NAME)

make_libft:
	@make all -C ./libft

make_printf:
	@make all -C ./printf

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS) $(GNLOBJS)
	$(CC) $(CFLAGS) $(GNLOBJS) $(OBJS) -I $(LIB) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(GNLOBJS)
	make clean -C ./libft
	make clean -C ./printf
	make clean -C ./mlx

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
	make fclean -C ./printf
	make clean -C ./mlx

re: fclean all

.PHONY: all clean fclean re
