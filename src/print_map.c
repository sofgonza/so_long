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
	int	x;
	int	y;

	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, 1080, 1080, "so_long");
	x = 0;
	y = 0;
	while (x <= 1080)
	{
		mlx_pixel_put(info->mlx, info->mlx_win, x, y, 0xffffff);
		++x;
		y += 10;
	}
	// info->minfo.desk = init_xpm(info, "desktop.xpm");
	// print_map(info);
	mlx_loop(info->mlx);
    return (0);
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
            put_img(info, info->minfo.desk, (i * 70), (j * 100));
            ++j;
        }
		++i;
	}
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

//mlx_put_image_to_window
void	put_img(t_info *info, void *img_ptr, int j, int i)
{
	mlx_put_image_to_window(info->mlx, info->mlx_win, img_ptr, j, i);
}
