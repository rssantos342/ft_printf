/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:50:16 by ride-sou          #+#    #+#             */
/*   Updated: 2023/04/28 16:33:05 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printstr(char *str);
int	ft_print_ptr(unsigned long long ptr);
int	ft_printnbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int num, const char format);
int	ft_printpercent(void);

#endif