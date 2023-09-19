/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:07:32 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/23 15:46:23 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// copiar mapa
char	**map_cpy(t_info *info)
{
	int		j;
	char	**map_copy;
	
	j = 0;
	while(info->minfo.map[j])
		++j;
	map_copy = malloc (sizeof(char **) * (j + 1));
	if (!map_copy)
		return (NULL);
	j = 0;
	while(info->minfo.map[j])
	{
		map_copy[j] = info->minfo.map[j];			
		++j;
	}
	map_copy[j] = 0;
	return (map_copy);
}

// reemplazar '0' y 'C' por ' '
char **chech_path(char **map, int y, int x)
{
	test_print_map(map);
	map[y][x] = ' ';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E' 
		&& map[y - 1][x] != ' ')
		chech_path(map, (y - 1), x);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E'
		&& map[y + 1][x] != ' ')
		chech_path(map, (y + 1), x);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E'
		&& map[y][x - 1] != ' ')
		chech_path(map, y, (x - 1));
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E'
		&& map[y][x + 1] != ' ')
		chech_path(map, y, (x + 1));
	return (map);
}

// controlar que no haya 'C' en el mapa
int	valid_path(char **map)
{
	int	y;
	int	x;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

// checkear en puntos cardinales al rededor de 'E' q alguno es ' '
int	exit_path(char **map, int y, int x)
{
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' 
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	map_parce(t_info *info)
{
	char	**map_copy;

	map_copy = map_cpy(info);
	find_player(info, map_copy);
	map_copy = chech_path(map_copy, info->pinfo.y, info->pinfo.x);
	if (!valid_path(map_copy))
	{
		str_free(map_copy);
		ft_error("invalid path\n");
	}
	find_exit(info, map_copy);
	if (!exit_path(map_copy, info->einfo.y, info->einfo.x))
	{
		str_free(map_copy);
		ft_error("invalid path\n");
	}
	str_free(map_copy);
	return (0);
}