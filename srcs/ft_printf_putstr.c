/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:15:48 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/15 18:54:53 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_printf_putstr(const char *str, t_list *flags)
{
	int i;
	int len;
	int n;

	len = ft_strlen(str);
	n = flags->width + flags->left + flags->zero - len;
	printf ("%d", n);
	i = 0;
	if (flags->precision == -1)
		return ;
	if (flags->precision)
	{
		if (flags->precision >= len)
			flags->precision = len;
		else
			len = flags->precision;
	}
	if (flags->width > len)
		flags->width -= len;
	else 
		flags->width = 0;
	if (flags->width)
	{
		while (n--)
			ft_putchar_printf(' ', flags);
	}
	else if (flags->zero)
	{
		while (n--)
			ft_putchar_printf('0', flags);
	}
	while (str[i] && i < len)
	{
		ft_putchar_printf(str[i], flags);
		i++;
	}
	if (flags->left)
	{
	while (n--)
			ft_putchar_printf(' ', flags);
	}
}
