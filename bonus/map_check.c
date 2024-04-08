/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:01:11 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/16 12:50:51 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(char *file, t_info *info)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Error\nInvalid file\n");
	}
	save_map(fd, info);
	rec_map(info);
	if (info->minfo.map_l > 26 || info->minfo.map_h > 13)
	{
		ft_error("Error\nInsert a smaller map\n");
		return (0);
	}
	close_map(info);
	map_chars(info);
	map_parce(info);
	return (0);
}

int	save_map(int fd, t_info *info)
{
	char	*line;
	char	*mapstr;

	line = "";
	mapstr = NULL;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			break ;
		}
		if (line[0] == '\n')
			ft_error("Error\nInvalid map\n");
		mapstr = gnl_strjoin(mapstr, line);
		free(line);
	}
	if (!mapstr)
		ft_error("Error\nEmpty file\n");
	info->minfo.map = ft_split(mapstr, '\n');
	info->minfo.map_cpy = ft_split(mapstr, '\n');
	free(mapstr);
	return (0);
}

int	rec_map(t_info *info)
{
	int	len2;
	int	i;

	i = 1;
	info->minfo.map_l = ft_strlen(info->minfo.map[0]);
	len2 = 0;
	while (info->minfo.map[i])
	{
		len2 = ft_strlen(info->minfo.map[i]);
		if (info->minfo.map_l != len2)
		{
			ft_error("Error\nInsert a rectangular map\n");
			return (0);
		}
		info->minfo.map_l = len2;
		++i;
	}
	info->minfo.map_h = i - 1;
	return (0);
}

int	close_map(t_info *info)
{
	int	len;
	int	i;
	int	j;

	len = (ft_strlen(info->minfo.map[0])) - 1;
	j = 0;
	while (info->minfo.map[j])
	{
		i = 0;
		while (i <= len && (j == 0 || !(info->minfo.map[j + 1])))
		{
			if (info->minfo.map[j][i] != '1')
				ft_error("Error\nMap not closed by walls\n");
			++i;
		}
		if (info->minfo.map[j][0] != '1' || info->minfo.map[j][len] != '1')
			ft_error("Error\nMap not closed by walls\n");
		++j;
	}
	return (0);
}
