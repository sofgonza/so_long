/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:48:31 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 17:44:05 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			(*f)(i, &s[i]);
	}
}
/*
#include <stdio.h>
void ft_nothing(unsigned int a, char *s)
{
	s[0] = s[a];
}

int	main(void)
{
	char	s[] = "prrooobbaannddoo";
	printf("original str = %s\n", s);
	ft_striteri(s, &ft_nothing);
	printf("changed str = %s\n", s);
	return (0);
}*/
