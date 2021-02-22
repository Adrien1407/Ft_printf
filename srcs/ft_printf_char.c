/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:29:19 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 15:04:03 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_printf_char(const char c, t_list *flags)
{
	if (flags->left)
	{
		flags->left--;
		ft_putchar_printf(1, c, flags);
		ft_putchar_printf(flags->left, ' ', flags);
	}
	else if (flags->width)
	{
		flags->width--;
		ft_putchar_printf(flags->width, ' ', flags);
		ft_putchar_printf(1, c, flags);
	}
	else if (flags->zero && flags->id == '%')
	{
		flags->zero--;
		ft_putchar_printf(flags->zero, '0', flags);
		ft_putchar_printf(1, '%', flags);
	}
	else
		ft_putchar_printf(1, c, flags);
	return ;
}
