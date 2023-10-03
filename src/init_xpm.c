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

#include "so_long.h"

int init_mlx(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, (info->minfo.map_l * PXL_SIZE), ((info->minfo.map_h + 1) * PXL_SIZE), "so_long");
	mlx_hook(info->mlx_win, 17, 0, red_cross, info);
	save_xpm(info);
	mlx_key_hook(info->mlx_win, key_hooks, info);
	//mlx_loop_hook(info->mlx, &loop_hook, &info);
	mlx_loop(info->mlx);
    return (0);
}

void	save_xpm(t_info *info)
{
	info->minfo.walls = init_xpm(info, "desktop.xpm");
	info->minfo.ground = init_xpm(info, "floor.xpm");
	info->minfo.exit = init_xpm(info, "stapler.xpm");
	info->minfo.coins = init_xpm(info, "paper.xpm");
	info->minfo.playerw = init_xpm(info, "dwight.xpm");
	info->minfo.playera = init_xpm(info, "dwight.xpm");
	info->minfo.players = init_xpm(info, "dwight.xpm");
	info->minfo.playerd = init_xpm(info, "dwight.xpm");
}

void	*init_xpm(t_info *info, char *str)
{
	char	*route;
	void	*img;

	route = ft_strjoin("./xpm/", str);
	img = mlx_xpm_file_to_image(info->mlx, route, &info->img_width, &info->img_height);
	if (!img)
		ft_error("Failed to load XPM files");
	free(route);
	return (img);
}

int	red_cross(t_info *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit (0);
}