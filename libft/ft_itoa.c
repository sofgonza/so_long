/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:01:50 by sofgonza          #+#    #+#             */
/*   Updated: 2023/05/22 12:04:18 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n && ++len)
		n = n / 10;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		t;

	len = digit_count(n);
	t = 0;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[--len] = (n % 10) + 48;
		else
			str[--len] = (n % 10 * -1) + 48;
		n = n / 10;
	}
	return (str);
}
/*
int	main(void)
{
	int	i;
	
	i = -623;
	printf("%s\n", ft_itoa(i));
	return (0);
}*/
