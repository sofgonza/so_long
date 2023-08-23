/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:44:36 by sofgonza          #+#    #+#             */
/*   Updated: 2023/06/05 21:59:47 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *format, va_list arg)
{
	int		i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (*format == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (*format == 'p')
		i += ft_putptr(va_arg(arg, unsigned long long int));
	else if (*format == 'd' || *format == 'i')
		i += ft_putnbr(va_arg (arg, int));
	else if (*format == 'u')
		i += ft_putnbr_uns(va_arg(arg, unsigned int));
	else if (*format == 'x' || *format == 'X')
		i += ft_puthex(va_arg(arg, unsigned int), *format);
	else if (*format == '%')
		i += ft_putchar(*format);
	else
		return (0);
	return (i);
}

int	ft_printf(char const *format, ...)
{
	int		aux;
	int		i;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	while (*format)
	{
		aux = 0;
		if (*format == '%')
		{
			++format;
			aux = ft_format((char *)format++, arg);
			if (aux < 0)
				return (-1);
			i += aux;
		}
		else
		{
			if (ft_putchar(*(format)++) == -1)
				return (-1);
			i++;
		}
	}
	return (va_end(arg), i);
}
