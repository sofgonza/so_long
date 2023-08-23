/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:45:36 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/05 18:03:35 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_info *info)
{
	info->map = NULL;
	info->player = 0;
	info->coins = 0;
	info->exit = 0;
	info->walls = 0;
	info->ground = 0;
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (0);
}

void	print_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		++i;
	}
	ft_printf("\n");
}