/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:57:33 by sofgonza          #+#    #+#             */
/*   Updated: 2023/05/26 12:06:31 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (str != NULL)
	{
		ft_strlcpy(str, (char *)s1, (lens1 + 1));
		ft_strlcat(str, (char *)s2, (lens1 + lens2 + 1));
		return (str);
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strjoin("hola como va ", "todo bien"));
	return (0);
}*/
