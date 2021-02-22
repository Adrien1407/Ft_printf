/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:57:03 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 16:45:48 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_count_digits(long int n)
{
	int			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_recursive(long c, t_list *flags)
{
	if (c < 0)
		c = -c;
	if (c > 9)
		ft_putnbr_recursive(c / 10, flags);
	c = c % 10 + 48;
	ft_putchar_printf(1, c, flags);
}

void		ft_putnbr(long c, t_list *flags)
{
	int len;
	int precision;

	precision = 0;
	len = ft_count_digits(c);
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
		ft_putnbr_recursive(c, flags);
	if (flags->left > len)
		ft_putchar_printf((flags->left - (len + (c < 0))), ' ', flags);
}
