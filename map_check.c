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

#include "so_long.h"

int	check_map(char *file, t_info *info)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("invalid file");
	}
	save_map(fd, info);
	rec_map(info);
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
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			break ;
		}
		if (line[0] == '\n')
			ft_error("Invalid map");
		mapstr = gnl_strjoin(mapstr, line);
		free(line);
	}
	if (!mapstr)
		ft_error("empty file");
	info->map = ft_split(mapstr, '\n');
	free(mapstr);
	return (0);
}

int	rec_map(t_info *info)
{
	int	len;
	int	len2;
	int	i;

	i = 1;
	len = ft_strlen(info->map[0]);
	len2 = 0;
	while (info->map[i])
	{
		len2 = ft_strlen(info->map[i]);
		if (len != len2)
		{
			ft_error("insert a rectangular map");
			return (0);
		}
		len = len2;
		++i;
	}
	return (0);
}

int	close_map(t_info *info)
{
	int	len;
	int	i;
	int	j;

	len = (ft_strlen(info->map[0])) - 1;
	j = 0;
	while (info->map[j])
	{
		i = 0;
		while (i <= len && (j == 0 || !(info->map[j + 1])))
		{
			if (info->map[j][i] != '1')
				ft_error("map not closed by top/down walls\n");
			++i;
		}
		if (info->map[j][0] != '1' || info->map[j][len] != '1')
			ft_error("map not closed by lateral walls\n");
		++j;
	}
	return (0);
}
