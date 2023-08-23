/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:30:03 by sofgonza          #+#    #+#             */
/*   Updated: 2023/06/05 21:53:19 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr(unsigned long long n)
{
	int		i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthex_ptr(n / 16);
		i += ft_puthex_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			i += ft_putchar(n + 48);
		else
			i += ft_putchar(n - 10 + 'a');
	}
	return (i);
}

int	ft_putptr(unsigned long long n)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_puthex_ptr(n);
	return (i);
}
