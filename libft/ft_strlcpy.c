/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:25:14 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 14:51:47 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	src_size;

	x = 0;
	src_size = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[x] != '\0' && x < (dstsize - 1))
		{
			dest[x] = src[x];
			++x;
		}
		dest[x] = '\0';
	}
	return (src_size);
}
/*
#include <stdio.h>
int	main(void)
{
	char	dest[] = "ansld";
	char	src[] = "holga";
	size_t	size = (ft_strlen(src) + 1);
	printf("%d\n%s\n", ft_strlcpy(dest, src, size), dest);
	return (0);
}*/
