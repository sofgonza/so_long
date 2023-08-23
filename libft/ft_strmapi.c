/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:16 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 17:52:36 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	int					len;
	char				*str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		++i;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

char ft_nothing(unsigned int i, char a)
{
	a = 'x';
	(void) i;
	return (a);
}

int	main(void)
{
	const char	s[] = "tester";
	printf("original str = %s\nchanged str = %s\n", s, ft_strmapi(s, &ft_nothing));
	return (0);
}*/
