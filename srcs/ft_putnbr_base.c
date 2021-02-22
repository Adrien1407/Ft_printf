/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:22:12 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 16:46:09 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static	int	ft_count_hexa(long int n)
{
	int			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	ft_putnbr2(long c, t_list *flags)
{
	char *base;

	base = "0123456789abcdef";
	if (flags->id == 'X')
		base = "0123456789ABCDEF";
	if (c > 15)
		ft_putnbr2((c / 16), flags);
	ft_putchar_printf(1, base[c % 16], flags);
}

void		ft_putnbr_base2(long c, t_list *flags)
{
	int len;
	int precision;

	precision = 0;
	len = ft_count_hexa(c);
	if (flags->precision == -1 && (c == 0))
		len = 0;
	if (flags->precision > len)
	{
		precision = flags->precision - len;
		len = flags->precision;
	}
	if (flags->width > len)
		ft_putchar_printf((flags->width - (len + (c < 0))), ' ', flags);
	if (c < 0)
		ft_putchar_printf(1, '-', flags);
	if (flags->zero > len)
		ft_putchar_printf((flags->zero - (len + (c < 0))), '0', flags);
	ft_putchar_printf(precision, '0', flags);
	if (len)
		ft_putnbr2(c, flags);
	if (flags->left > len)
		ft_putchar_printf((flags->left - (len + (c < 0))), ' ', flags);
}
