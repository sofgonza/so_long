/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
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
	info->mlx_win = mlx_new_window(info->mlx, 1080, 1080, "so_long");
	save_xpm(info);
	print_map(info);
	mlx_loop(info->mlx);
    return (0);
}

void	save_xpm(t_info *info)
{
	info->minfo.walls = init_xpm(info, "desktop.xpm");
	info->minfo.ground = init_xpm(info, "stapler.xpm");
	info->minfo.exit = init_xpm(info, "stapler.xpm");
	info->minfo.coins = init_xpm(info, "paper.xpm");
	info->minfo.player = init_xpm(info, "dwight.xpm");
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

void	print_map(t_info *info)
{
	int	i;
    int j;
	
	i = 0;
	while (info->minfo.map[i])
	{
        j = 0;
        while (info->minfo.map[i][j])
        {
            put_elem(info, i, j);
            ++j;
        }
		++i;
	}
}

void	put_elem(t_info *info, int i, int j)
{
	put_img(info, info->minfo.ground, j, i);
	if (info->minfo.map[i][j] == '1')
	{
		put_img(info, info->minfo.walls, j, i);
	}
	else if (info->minfo.map[i][j] == 'E' && info->coins != 0)
		put_img(info, info->minfo.exit, j, i);
	else if (info->minfo.map[i][j] == 'C')
		put_img(info, info->minfo.coins, j, i);
	else
		put_img(info, info->minfo.ground, j, i);
}

void	put_img(t_info *info, void *img_ptr, int j, int i)
{
	mlx_put_image_to_window(info->mlx, info->mlx_win, img_ptr, j * 110, i * 110);
}
