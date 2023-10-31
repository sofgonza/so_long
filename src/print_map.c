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

// recorre el mapa y va llamando para imprimir posición por posición
void	print_map(t_solong *info, char key)
{
	int	i;
	int	j;

	i = 0;
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

void	put_elem(t_solong *info, int i, int j)
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

// dirección de mirada del jugador dependiendo hacia donde se mueve
void	put_player(t_solong *info, int i, int j, char key)
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

void	put_img(t_solong *info, void *img_ptr, int j, int i)
{
	mlx_put_image_to_window(info->mlxinfo.mlx, info->mlxinfo.win, img_ptr,
		j * PXL_SIZE, i * PXL_SIZE);
}
