/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabraham <sabraham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:40:48 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/20 20:38:33 by sabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static	int	ft_conversion(va_list vl, const char format)
{
	int	total_char;

	total_char = 0;
	if (format == 'c')
		total_char += ft_putchar(va_arg(vl, int));
	else if (format == 's')
		total_char += ft_putstr(va_arg(vl, char *));
	else if (format == 'p')
		total_char += ft_putptr(va_arg(vl, uintptr_t));
	else if (format == 'd' || format == 'i')
		total_char += ft_putnbr(va_arg(vl, int));
	else if (format == 'u')
		total_char += ft_putunsigned(va_arg(vl, unsigned int));
	else if (format == 'x' || format == 'X')
		total_char += ft_puthex(va_arg(vl, unsigned int), format);
	else if (format == '%')
		total_char += ft_putchar('%');
	return (total_char);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	vl;
	int		total_char;

	i = 0;
	total_char = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			total_char += ft_conversion(vl, format[i + 1]);
			i++;
		}
		else
			total_char += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (total_char);
}
