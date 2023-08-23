/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:28:27 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 16:41:10 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	n;

	x = 0;
	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	while (x < len && haystack[x] != '\0')
	{
		i = 0;
		while (haystack[x + i] == needle[i] && x + i < len && needle[i] != '\0')
			i++;
		if (i == n)
			return ((char *)haystack + x);
		x++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	s1[] = "hola como estas";
	const char	s2[] = "como";
	printf("haystack = %s\nneedle = %s\n%s", s1, s2, ft_strnstr(s1, s2, 20));
	return (0);
}*/
