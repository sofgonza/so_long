/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:26:31 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/11 15:08:02 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc == 2 && check_ber(argv[1]))
	{
		info = malloc(sizeof(t_info));
		if (!info)
			return (0);
		init_vars(info);
		check_map(argv[1], info);
		init_mlx();
		free(info);
	}
	else
	{
		ft_printf("invalid map file");
		exit(1);
	}
	return (0);
}

int init_mlx(void)
{
	void	*mlx;
	void	*mlx_wim;

	mlx = mlx_init();
	mlx_wim = mlx_new_window(mlx, 1080, 1080, "so_long");
	mlx_loop(mlx);
	return (0);
}
