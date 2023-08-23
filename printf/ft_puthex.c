/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:09:26 by sofgonza          #+#    #+#             */
/*   Updated: 2023/05/25 20:06:09 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthex(n / 16, format);
		i += ft_puthex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			i += ft_putchar(n + 48);
		else
		{
			if (format == 'x')
				i += ft_putchar(n - 10 + 'a');
			else if (format == 'X')
				i += ft_putchar(n - 10 + 'A');
		}
	}
	return (i);
}
