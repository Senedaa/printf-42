/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabraham <sabraham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:40:40 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/20 20:39:52 by sabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int ft_putchar(char c)
// {
//     write(1, &c, 1);
//     return 1;
// }

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0 ;
	if (n >= 10)
	{
		count += ft_putunsigned(n / 10);
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
