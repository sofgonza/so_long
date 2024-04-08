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
NAME_BONUS = so_long_bonus

RM = rm -f

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
MLX = ./mlx/libmlx.a
LIB = ./includes/so_long.h
SRC_PATH = ./src/
SRC_BONUS_PATH = ./bonus/

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

SRC_BONUS = so_long.c \
		map_check.c \
		map_check_utils.c \
		so_long_utils.c \
		parce.c \
		parce_utils.c \
		print_map.c \
		init_xpm.c \
		key_hooks.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_libft make_printf make_mlx $(NAME)

bonus: make_libft make_printf make_mlx $(NAME_BONUS)

make_libft:
	@make all -C ./libft

make_printf:
	@make all -C ./printf

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS) $(GNLOBJS)
	$(CC) $(CFLAGS) $(GNLOBJS) $(OBJS) -I $(LIB) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(GNLOBJS)
	$(CC) $(CFLAGS) $(GNLOBJS) $(OBJS_BONUS) -I $(LIB) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(GNLOBJS)
	$(RM) $(OBJS_BONUS) $(GNLOBJS)
	make clean -C ./libft
	make clean -C ./printf
	make clean -C ./mlx

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make fclean -C ./libft
	make fclean -C ./printf
	make clean -C ./mlx

re: fclean all

.PHONY: all clean fclean re bonus
