/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:07:32 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/23 15:46:29 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	str_free(char **str)
{
	unsigned int	j;

	j = 0;
	while (str[j])
	{
		free (str[j]);
		++j;
	}
	free (str);
}

void	find_player(t_info *info, char **map)
{
	info->pinfo.y = 0;
	while (map[info->pinfo.y])
	{
		info->pinfo.x = 0;
		while (map[info->pinfo.y][info->pinfo.x] != '\0'
			&& map[info->pinfo.y][info->pinfo.x] != 'P' )
			info->pinfo.x++;
		if (map[info->pinfo.y][info->pinfo.x] == 'P')
			return ;
		info->pinfo.y++;
	}
}

void	find_exit(t_info *info, char **map)
{
	info->einfo.y = 0;
	while (map[info->einfo.y])
	{
		info->einfo.x = 0;
		while (map[info->einfo.y][info->einfo.x] != '\0'
			&& map[info->einfo.y][info->einfo.x] != 'E' )
			info->einfo.x++;
		if (map[info->einfo.y][info->einfo.x] == 'E')
			return ;
		info->einfo.y++;
	}
}
