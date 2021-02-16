/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:15:48 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/16 16:49:39 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_printf_putstr(const char *str, t_list *flags)
{
	int i;
	int len;
	int n;

	i = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	n = (flags->width + flags->left + flags->zero) - len;
	if (n < 0)
		n = 0;
	if (flags->precision == -1)
		len = 0;
	else if (flags->precision && flags->precision < len)
		len = flags->precision;
	if (flags->width > len)
	{
		flags->width = flags->width - len;
		while (flags->width--)
			ft_putchar_printf(' ', flags);
	}
	while (str[i] && i < len)
		ft_putchar_printf(str[i++], flags);
	if (flags->left > len)
	{
		flags->left -= len;
		while (flags->left--)
			ft_putchar_printf(' ', flags);
	}
}
