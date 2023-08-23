/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:34:50 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 15:22:38 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		--len;
	}
	if ((char)c == '\0')
		return ((char *)&s[len]);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strrchr("teste", 'e'));
	return (0);
}*/
