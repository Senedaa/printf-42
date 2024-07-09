/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabraham <sabraham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:36:20 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/20 20:39:39 by sabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checknegative(int n, int count)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
		count += 2;
	}
	else
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	count += ft_putnbr(n);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = ft_checknegative(n, count);
	}
	else if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
		count++;
	}
	else
	{
		ft_putchar(n + '0');
		count++;
	}
	return (count);
}
