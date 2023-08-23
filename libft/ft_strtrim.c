/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:43:43 by sofgonza          #+#    #+#             */
/*   Updated: 2023/05/27 14:44:01 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	int		len;

	if (!s1 || !set)
		return (NULL);
	x = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[x]) != NULL && s1[x])
		++x;
	while (ft_strchr(set, s1[len - 1]) != NULL && (len - 1))
		len--;
	len = len - x;
	return (ft_substr(s1, x, len));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_strtrim("ababababbbaabholaababbababba", "ab"));
	return (0);
}
*/
