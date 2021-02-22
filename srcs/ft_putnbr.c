/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:57:03 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 12:05:07 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putnbr_recursive(long c, t_list *flags)
{
	if (c < 0)
		c = -c;
	if (c > 9)
		ft_putnbr_recursive(c / 10, flags);
	c = c % 10 + 48;
	ft_putchar_printf(c, flags);
}
void	ft_putnbr(long c, t_list *flags)
{
	int len;
	int precision;

	precision = 0;
	len = ft_count_digits(c);
	if (((flags->zero) && ((flags->precision > 0) || (flags->precision == -1))))
	{
		flags->width = flags->zero;
		flags->zero = 0;
	}
	if (flags->precision == -1 && (c == 0))
		len = 0;
	if (flags->precision > len)
	{
		precision = flags->precision - len;
		len = flags->precision;
	}
	if (flags->width > len)
	{
		flags->width -= len + (c < 0);
		while (flags->width--)
			ft_putchar_printf(' ', flags);
	}
	if (c < 0)
		ft_putchar_printf('-', flags);
	if (flags->zero > len)
	{
		flags->zero -= len + (c < 0);
		while (flags->zero--)
			ft_putchar_printf('0', flags);
	}
	while (precision--)
		ft_putchar_printf('0', flags);
	if (len)
		ft_putnbr_recursive(c, flags);
	if (flags->left > len)
	{
		flags->left -= len + (c < 0);
		while (flags->left--)
			ft_putchar_printf(' ', flags);
	}
}
