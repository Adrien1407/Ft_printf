/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:15:48 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/12 18:48:36 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_printf_putstr(const char *str, t_list *flags)
{
	int i;
	int len;
	int n;

	len = ft_strlen(str);
	n = ((flags->zero + flags->left + flags->width) - len);
	i = 0;
	if (flags->precision == -1)
			return ;
	
	if (flags->precision && flags->precision < len)
		len = flags->precision;
	if(flags->width)
	{
		while (n && n > 0)
		{
			ft_putchar_printf(' ', flags);
			n--;
		}
	}
	if (flags->zero)
	{
		while (n && n > 0)
		{
			ft_putchar_printf('0', flags);
			n--;
		}
	}
	while(str[i] && i < len)
	{
		ft_putchar_printf(str[i], flags);
		i++;
	}
	if (flags->left)
	{
		while (n && n > 0)
		{
			ft_putchar_printf(' ', flags);
			n--;
		}
	}
}
