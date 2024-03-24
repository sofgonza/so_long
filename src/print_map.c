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

#include "../includes/so_long.h"

void	moves_on_frame(t_info *info)
{
	char	*moves;

	moves = ft_itoa(info->pinfo.mov++;);
	mlx_string_put(info->mlxinfo.mlx, info->mlxinfo.win, 10, 20, 0xFFFFFF, "Moves:");
	mlx_string_put(info->mlxinfo.mlx, info->mlxinfo.win, 75, 20, 0xFFFFFF, moves);
	free(moves);
}

void	print_map(t_info *info, char key)
{
	int	i;
	int	j;

	i = 0;
	moves_on_frame(t_info *info);
	while (info->minfo.map[i])
	{
		j = 0;
		while (info->minfo.map[i][j])
		{
			put_elem(info, i, j);
			if (info->minfo.map[i][j] == 'P')
				put_player(info, i, j, key);
			++j;
		}
		++i;
	}
}

void	put_elem(t_info *info, int i, int j)
{
	put_img(info, info->mlxinfo.ground, j, i);
	if (info->minfo.map[i][j] == '1')
	{
		put_img(info, info->mlxinfo.walls, j, i);
	}
	else if (info->minfo.map[i][j] == 'E' && info->coins != 0)
		put_img(info, info->mlxinfo.noexit, j, i);
	else if (info->minfo.map[i][j] == 'E' && info->coins == 0)
		put_img(info, info->mlxinfo.exit, j, i);
	else if (info->minfo.map[i][j] == 'C')
		put_img(info, info->mlxinfo.coins, j, i);
	else
		put_img(info, info->mlxinfo.ground, j, i);
}

void	put_player(t_info *info, int i, int j, char key)
{
	if (key == 's')
		put_img(info, info->mlxinfo.players, j, i);
	else if (key == 'w')
		put_img(info, info->mlxinfo.playerw, j, i);
	else if (key == 'a')
		put_img(info, info->mlxinfo.playera, j, i);
	else if (key == 'd')
		put_img(info, info->mlxinfo.playerd, j, i);
}

void	put_img(t_info *info, void *img_ptr, int j, int i)
{
	mlx_put_image_to_window(info->mlxinfo.mlx, info->mlxinfo.win, img_ptr,
		j * PXL_SIZE, i * PXL_SIZE);
}
