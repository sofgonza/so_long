/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:42:18 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 16:41:29 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	sign;
	int	num;

	x = 0;
	sign = 1;
	num = 0;
	while ((str[x] == ' ' || str[x] == '\n' || str[x] == '\f'
			|| str[x] == '\r' || str[x] == '\t' || str[x] == '\v'))
		++x;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sign = sign * -1;
		++x;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		num = num * 10 + (str[x] - 48) * sign;
		++x;
	}
	return (num);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = " +-1";
	int	num = ft_atoi(str);
	printf ("integer:%d\n", num);
	printf ("function:%d", atoi(str));
	return (0);
}*/
