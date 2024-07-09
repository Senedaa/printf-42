/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabraham <sabraham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:40:44 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/20 20:37:59 by sabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex_recursive(unsigned int num, const char format)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_put_hex_recursive(num / 16, format);
		num = (num % 16);
	}
	if (num <= 9)
		count += ft_putchar((num % 16) + '0');
	else
	{
		if (format == 'x')
			count += ft_putchar((num % 16) - 10 + 'a');
		else if (format == 'X')
			count += ft_putchar((num % 16) - 10 + 'A');
	}
	return (count);
}

int	ft_puthex(unsigned int num, const char format)
{
	int	count;

	count = 0;
	if (num == 0)
		count += ft_putchar('0');
	else
		return (ft_put_hex_recursive(num, format));
	return (count);
}
