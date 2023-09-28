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

typedef struct s_player
{
	int	x;
	int	y;
	int	mov;
}	t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

typedef struct s_map
{
	char	**map;
	char	**map_cpy;
	int		map_l;
	int		map_h;
	void	*walls;
	void	*ground;
	void	*exit;
	void	*coins;
	void	*player;
}	t_map;

typedef struct s_info
{
	t_player	pinfo;
	t_exit		einfo;
	t_map		minfo;
	void		*mlx;
	void		*mlx_win;
	int			img_width;
	int			img_height;
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
char 	**chech_path(char **map, int y, int x);
int		valid_path(char **map);
int		exit_path(char **map, int y, int x);
void 	find_player(t_info *info, char **map);
void	find_exit(t_info *info, char **map);
void	str_free(char **str);

// UTILS
void	init_vars(t_info *info);
void	ft_error(char *str);

// MAP PRINT
// inicializar mlx y abrir ventana + loop
// print_map(t_info	*info) --> recorrrer el mapa y enviar cada posición a put_img
// put_img --> mlx_xpm_file_to_image() && mls_put_image_to_window()
int	init_mlx(t_info *info);

void	test_print_map(char **map);
void	*init_xpm(t_info *info, char *str);
void	save_xpm(t_info *info);
void	put_elem(t_info *info, int j,int i);
void	put_img(t_info *info, void *img_ptr, int j, int i);
void	print_map(t_info *info);


#endif
