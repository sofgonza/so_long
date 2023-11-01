/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:05:44 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/23 16:12:10 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check .ber
int	check_ber(char	*argv)
{
	int		i;

	i = 0;
	while (argv[i] != '.')
		++i;
	if (argv[i - 1] == 47)
		return (0);
	if (argv[i] == '.')
	{
		if (argv[i + 1] != 'b' || argv[i + 2] != 'e'
			|| argv[i + 3] != 'r')
			return (0);
		i += 4;
	}
	if (argv[i] != '\0')
		return (0);
	return (1);
}

// check caracteres del mapa
int	map_chars(t_info *info)
{
	int	j;
	int	i;

	j = 0;
	while (info->minfo.map[j])
	{
		i = 0;
		while (info->minfo.map[j][i])
		{
			check_chars(info->minfo.map[j][i], info);
			++i;
		}
		++j;
	}
	count_chars(info);
	return (0);
}

int	check_chars(char c, t_info *info)
{
	if (c == 'C')
		info->coins++;
	else if (c == 'P')
		info->player++;
	else if (c == 'E')
		info->exit++;
	else if (c == '1')
		info->walls++;
	else if (c == '0')
		info->ground++;
	else
		ft_error("Error\nInvalid chars in mapfile\n");
	return (0);
}

int	count_chars(t_info *info)
{
	if (info->coins < 1)
		ft_error("Error\nNot enough collectibles\n");
	else if (info->player != 1)
		ft_error("Error\nStart point not given\n");
	else if (info->exit != 1)
		ft_error("Error\nNo exit\n");
	return (0);
}
