/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_address.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:22:12 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/19 14:17:38 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putnbr3(long c, t_list *flags)
{
	char *base;

	base = "0123456789abcdef";
	if (c > 15)
		ft_putnbr3((c / 16), flags);
	ft_putchar_printf(base[c % 16], flags);
}
void	ft_putnbr_base_address(long c, t_list *flags)
{
	int len;
	int precision;

	precision = 0;
	len = ft_count_address(c);
	if (flags->precision == -1 && (c == 0))
		len = 0;
	if (!c)
		len += 2;
	if (flags->precision > len)
	{
		precision = flags->precision - len;
		len = flags->precision;
	}
	if (flags->zero && flags->precision > 0 )
	{
		flags->width = flags->zero;
		flags->zero = 0;
	}
	if (flags->width > len)
	{
		flags->width -= len + (c < 0);
		while (flags->width--)
			ft_putchar_printf(' ', flags);
	}
			ft_putchar_printf('0', flags);
			ft_putchar_printf('x', flags);
	if (flags->zero > len)
	{
		flags->zero -= len + (c < 0);
		while (flags->zero--)
			ft_putchar_printf('0', flags);
	}
	while (precision--)
		ft_putchar_printf('0', flags);
	if (!(c == 0 && flags->precision == -1))
		ft_putnbr3(c, flags);
	if (flags->left > len)
	{
		flags->left -= len + (c < 0);
		while (flags->left--)
			ft_putchar_printf(' ', flags);
	}
}
