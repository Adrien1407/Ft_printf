/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:57:03 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/11 14:57:49 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putnbr(long c, t_list *flags)
{
	int len;

	len = 0;
	if(flags->width)
	{
		flags->width = flags->width - ft_count_digits(c);
		while(flags->width > 0)
	{
	ft_putchar_printf(' ',flags);
	flags->width--;
}
	}
	if (c < 0)
	{
		c = -c;
		ft_putchar_printf('-', flags);
	}
	if (c > 9)
		ft_putnbr(c / 10, flags);
	c = c % 10 + 48;
	ft_putchar_printf(c, flags);
}
