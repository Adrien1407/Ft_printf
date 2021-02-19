/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:29:19 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/19 15:00:19 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_printf_char(const char c, t_list *flags)
{
	if (flags->left)
	{
		flags->left--;
		ft_putchar_printf(c, flags);
		while (flags->left--)
			ft_putchar_printf(' ', flags);
	}
	else if (flags->width)
	{
		flags->width--;
		while (flags->width--)
			ft_putchar_printf(' ', flags);
		ft_putchar_printf(c, flags);
	}
	else if (flags->zero && flags->id == '%')
	{
		flags->zero--;
		while (flags->zero--)
			ft_putchar_printf('0', flags);
		ft_putchar_printf('%', flags);
	}
	else
		ft_putchar_printf(c, flags);
	return ;
}
