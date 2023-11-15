/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:30:19 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/11 15:14:40 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# define ESC_KEY		53
# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define PXL_SIZE		96
# define XPM_ROUTE		"./xpm/"

// INFO PLAYER
typedef struct s_player
{
	int	x;
	int	y;
	int	mov;
}	t_player;

// INFO EXIT
typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

// MAPA
typedef struct s_map
{
	char	**map;
	char	**map_cpy;
	int		map_l;
	int		map_h;
}	t_map;

// IMÁGENES MLX
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	void	*walls;
	void	*ground;
	void	*exit;
	void	*noexit;
	void	*coins;
	void	*playerw;
	void	*playera;
	void	*players;
	void	*playerd;
}	t_mlx;

// ESTRUCTURA PRINCIPAL
typedef struct s_info
{
	t_player	pinfo;
	t_exit		einfo;
	t_map		minfo;
	t_mlx		mlxinfo;
	int			player;
	int			coins;
	int			exit;
	int			walls;
	int			ground;
}	t_info;

// MAP CHECK
int		check_ber(char	*argv);
int		check_map(char *file, t_info *info);
int		save_map(int fd, t_info *info);
int		rec_map(t_info *info);
int		close_map(t_info *info);
int		map_chars(t_info *info);
int		check_chars(char c, t_info *info);
int		count_chars(t_info *info);

// MAP PARCE
int		map_parce(t_info *info);
char	**map_cpy(t_info *info);
char	**chech_path(char **map, int y, int x);
int		valid_path(char **map);
int		exit_path(char **map, int y, int x);
void	find_player(t_info *info, char **map);
void	find_exit(t_info *info, char **map);
void	str_free(char **str);

// UTILS
void	init_vars(t_info *info);
void	ft_error(char *str);
void	ft_exit(char *str);

// INICIALIZAR XPM
int		init_mlx(t_info *info);
void	*init_xpm(t_info *info, char *str);
void	save_xpm(t_info *info);
int		red_cross(t_info *info);

// MAP PRINT
void	print_map(t_info *info, char key);
void	put_elem(t_info *info, int i, int j);
void	put_player(t_info *info, int i, int j, char key);
void	put_img(t_info *info, void *img_ptr, int j, int i);

// KEY HOOKS
int		key_hooks(int key_code, t_info *info);
void	w_press(t_info *info);
void	a_press(t_info *info);
void	s_press(t_info *info);
void	d_press(t_info *info);

#endif
