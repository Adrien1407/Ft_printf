/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_address.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:22:12 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 16:46:41 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_count_address(long int n)
{
	int		i;

	i = 2;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	ft_putnbr3(long c, t_list *flags)
{
	char *base;

	base = "0123456789abcdef";
	if (c > 15)
		ft_putnbr3((c / 16), flags);
	ft_putchar_printf(1, base[c % 16], flags);
}

void		ft_putnbr_base_address(long c, t_list *flags)
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
	if (flags->width > len)
		ft_putchar_printf((flags->width - (len + (c < 0))), ' ', flags);
	ft_putchar_printf(1, '0', flags);
	ft_putchar_printf(1, 'x', flags);
	if (flags->zero > len)
		ft_putchar_printf((flags->zero - (len + (c < 0))), '0', flags);
	ft_putchar_printf(precision, '0', flags);
	if (!(c == 0 && flags->precision == -1))
		ft_putnbr3(c, flags);
	if (flags->left > len)
		ft_putchar_printf((flags->left - (len + (c < 0))), ' ', flags);
}
