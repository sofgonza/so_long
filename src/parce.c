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
/*char	**map_cpy(t_info *info)
{
	int		j;
	int		i;
	char	**map_copy;
	
	j = 0;
	test_print_map(info->minfo.map);
	while(info->minfo.map[j])
		++j;
	map_copy = malloc (sizeof(char **) * (j + 1));
	if (!map_copy)
		return (NULL);
	j = 0;
	i = 0;
	while(info->minfo.map[j] != '\0')
	{
		i = 0;
		while(info->minfo.map[j][i] != '\0')
		{
			map_copy[j][i] = info->minfo.map[j][i];
			++i;
		}
		++j;
	}
	map_copy[j] = "\0";
	test_print_map(info->minfo.map);
	return (map_copy);
}*/

// reemplazar '0' y 'C' por ' '
char **chech_path(char **map, int y, int x)
{
	//test_print_map(map);
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
	//test_print_map(map);
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
	find_player(info, info->minfo.map_cpy);
	info->minfo.map_cpy = chech_path(info->minfo.map_cpy, info->pinfo.y, info->pinfo.x);
	if (!valid_path(info->minfo.map_cpy))
	{
		str_free(info->minfo.map_cpy);
		ft_error("invalid path\n");
	}
	find_exit(info, info->minfo.map_cpy);
	if (!exit_path(info->minfo.map_cpy, info->einfo.y, info->einfo.x))
	{
		str_free(info->minfo.map_cpy);
		ft_error("invalid path\n");
	}
	str_free(info->minfo.map_cpy);
	return (0);
}