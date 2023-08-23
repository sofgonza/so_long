/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:02:50 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 15:09:09 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char	a = 'a';
	printf("%d=%c\n%d=%c", a, a, ft_toupper((int)a), ft_toupper((inta));
	return (0);
}*/
