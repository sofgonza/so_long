/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:44:27 by sofgonza          #+#    #+#             */
/*   Updated: 2023/05/25 20:05:54 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *fromat, ...);
int	ft_format(char *format, va_list arg);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long long n);
int	ft_puthex_ptr(unsigned long long n);
int	ft_putnbr(int n);
int	ft_putnbr_uns(unsigned int n);
int	ft_puthex(unsigned int n, char format);

#endif
