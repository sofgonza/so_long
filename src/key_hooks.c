/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:05:44 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/23 16:12:10 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hooks(int key_code, t_info *info)
{
	if (key_code == ESC_KEY)
	{
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit(0);
	}
	if (key_code == W_KEY || key_code == ARROW_UP)
		w_press(info);
	if (key_code == A_KEY || key_code == ARROW_LEFT)
		a_press(info);
	if (key_code == S_KEY || key_code == ARROW_DOWN)
		s_press(info);
	if (key_code == D_KEY || key_code == ARROW_RIGHT)
		d_press(info);
	return (0);
}

void    w_press(t_info *info)
{
    if ((info->minfo.map[info->pinfo.y - 1][info->pinfo.x]) == 'C')
        info->coins++;
    if ((info->minfo.map[info->pinfo.y - 1][info->pinfo.x]) == 'E' 
		&& info->coins == info->allcoins)
        exit(0);
    if ((info->minfo.map[info->pinfo.y - 1][info->pinfo.x]) != '1'
		&& (info->minfo.map[info->pinfo.y - 1][info->pinfo.x]) != 'E')
	{
		info->minfo.map[info->pinfo.y][info->pinfo.x] = '0';
		info->minfo.map[info->pinfo.y - 1][info->pinfo.x] = 'P';
		info->pinfo.mov++;
		info->pinfo.y--;
		print_map(info, 'w');
	}
}

void    s_press(t_info *info)
{
	test_print_map(info->minfo.map);
    if ((info->minfo.map[info->pinfo.y + 1][info->pinfo.x]) == 'C')
        info->coins++;
    if ((info->minfo.map[info->pinfo.y + 1][info->pinfo.x]) == 'E' 
		&& info->coins == info->allcoins)
        exit(0);
    if ((info->minfo.map[info->pinfo.y + 1][info->pinfo.x]) != '1' 
		&& (info->minfo.map[info->pinfo.y + 1][info->pinfo.x]) != 'E')
	{
		info->minfo.map[info->pinfo.y][info->pinfo.x] = '0';
		info->minfo.map[info->pinfo.y + 1][info->pinfo.x] = 'P';
		info->pinfo.mov++;
		info->pinfo.y++;
		print_map(info, 's');
	}
}

void    a_press(t_info *info)
{
	test_print_map(info->minfo.map);
    if ((info->minfo.map[info->pinfo.y][info->pinfo.x - 1]) == 'C')
        info->coins++;
    if ((info->minfo.map[info->pinfo.y][info->pinfo.x - 1]) == 'E'
		&& info->coins == info->allcoins)
        exit(0);
    if ((info->minfo.map[info->pinfo.y][info->pinfo.x - 1]) != '1'
		&& (info->minfo.map[info->pinfo.y][info->pinfo.x - 1]) != 'E')
	{
		info->minfo.map[info->pinfo.y][info->pinfo.x] = '0';
		info->minfo.map[info->pinfo.y][info->pinfo.x - 1] = 'P';
		info->pinfo.mov++;
		info->pinfo.x--;
		print_map(info, 'a');
	}
}

void    d_press(t_info *info)
{
	test_print_map(info->minfo.map);
    if ((info->minfo.map[info->pinfo.y][info->pinfo.x + 1]) == 'C')
        info->coins++;
    if ((info->minfo.map[info->pinfo.y][info->pinfo.x + 1]) == 'E'
		&& info->coins == info->allcoins)
        exit(0);
    if ((info->minfo.map[info->pinfo.y][info->pinfo.x + 1]) != '1'
		&& (info->minfo.map[info->pinfo.y][info->pinfo.x + 1]) != 'E')
	{
		info->minfo.map[info->pinfo.y][info->pinfo.x] = '0';
		info->minfo.map[info->pinfo.y][info->pinfo.x + 1] = 'P';
		info->pinfo.mov++;
		info->pinfo.x++;
		print_map(info, 'd');
	}
}