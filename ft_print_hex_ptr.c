/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:44:33 by ride-sou          #+#    #+#             */
/*   Updated: 2023/05/02 10:59:57 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	ft_put_hex_ptr(unsigned long long num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex_ptr(num / 16, format);
		ft_put_hex_ptr(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x' || format == 'p')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex_ptr(num, format);
	return (ft_hex_ptr_len(num));
}

int	ft_print_ptr(unsigned long long ptr, const char format)
{
	int	print_len;

	print_len = 0;
	if (ptr == 0)
	{
		print_len += write(1, "(nil)", 5);
		return (5);
	}
	print_len += write(1, "0x", 2);
	ft_put_hex_ptr(ptr, format);
	print_len += ft_hex_ptr_len(ptr);
	return (print_len);
}
