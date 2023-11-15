/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:05:44 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/23 16:12:10 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_mlx(t_info *info)
{
	info->mlxinfo.mlx = mlx_init();
	if (!(info->mlxinfo.mlx))
		ft_error("Failed to load MLX");
	info->mlxinfo.win = mlx_new_window(info->mlxinfo.mlx,
			(info->minfo.map_l * PXL_SIZE),
			((info->minfo.map_h + 1) * PXL_SIZE), "so_long");
	if (!(info->mlxinfo.win))
		ft_error("Failed to load window");
	mlx_hook(info->mlxinfo.win, 17, 0, red_cross, info);
	save_xpm(info);
	print_map(info, 's');
	mlx_key_hook(info->mlxinfo.win, key_hooks, info);
	mlx_loop(info->mlxinfo.mlx);
	return (0);
}

void	save_xpm(t_info *info)
{
	info->mlxinfo.walls = init_xpm(info, "plants.xpm");
	info->mlxinfo.ground = init_xpm(info, "lake.xpm");
	info->mlxinfo.noexit = init_xpm(info, "plants.xpm");
	info->mlxinfo.exit = init_xpm(info, "yerba.xpm");
	info->mlxinfo.coins = init_xpm(info, "mate.xpm");
	info->mlxinfo.playerw = init_xpm(info, "carpinchow.xpm");
	info->mlxinfo.playera = init_xpm(info, "carpinchoa.xpm");
	info->mlxinfo.players = init_xpm(info, "carpinchos.xpm");
	info->mlxinfo.playerd = init_xpm(info, "carpinchod.xpm");
}

void	*init_xpm(t_info *info, char *str)
{
	char	*route;
	void	*img;

	route = ft_strjoin(XPM_ROUTE, str);
	img = mlx_xpm_file_to_image(info->mlxinfo.mlx, route,
			&info->mlxinfo.img_width, &info->mlxinfo.img_height);
	if (!img)
		ft_error("Error\nFailed to load XPM files\n");
	free(route);
	return (img);
}

int	red_cross(t_info *info)
{
	mlx_destroy_window(info->mlxinfo.mlx, info->mlxinfo.win);
	exit (0);
}
