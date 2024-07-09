/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabraham <sabraham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:40:33 by sabraham          #+#    #+#             */
/*   Updated: 2023/09/20 20:39:48 by sabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static void	ft_put_ptr_recursive(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_put_ptr_recursive(nb / 16);
		ft_put_ptr_recursive(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	ft_putptr(uintptr_t ptr)
{
	int	total_char;

	total_char = 0;
	total_char += write(1, "0x", 2);
	if (ptr == 0)
	{
		total_char += write(1, "0", 1);
	}
	else
	{
		ft_put_ptr_recursive(ptr);
		total_char += len_ptr(ptr);
	}
	return (total_char);
}
