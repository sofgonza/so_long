/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:16:55 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/05 17:03:59 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	x;
	size_t	slen;

	if (!s)
		return (NULL);
	sub = NULL;
	x = 0;
	slen = ft_strlen(s);
	if (len == 0 || slen == 0 || start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (x < len && (start + x) < slen)
	{
		sub[x] = s[start + x];
		++x;
	}
	sub[x] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	s1[] = "hola a";
	printf("s1=%s\ndifference=%s\n", s1, ft_substr(s1, 0, 6));
	return (0);
}*/
