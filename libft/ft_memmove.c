/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:39:46 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 14:30:48 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char		*s;
	unsigned char	*d;
	unsigned int	x;

	s = src;
	d = dest;
	x = 0;
	if (dest < src)
	{
		while (x < len)
		{
			d[x] = s[x];
			++x;
		}
		return (dest);
	}	
	if (dest == src || len == 0)
		return (dest);
	while (len-- > 0)
		d[len] = s[len];
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "342";
	char	dst[] = "holanvjerv";
	printf("%s", ft_memcpy(dst, src, 6));
	return (0);
}*/
