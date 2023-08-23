/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:46:35 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 15:17:45 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
		return (c);
	}
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char	a = 'A';
	printf("%d=%c\n%d=%c", a, a, ft_tolower((int)a), ft_tolower((int)a));
	return (0);
}*/
