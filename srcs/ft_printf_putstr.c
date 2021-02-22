/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:15:48 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 15:04:40 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_printf_putstr(const char *str, t_list *flags)
{
	int i;
	int len;

	i = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision == -1)
		len = 0;
	else if (flags->precision && flags->precision < len)
		len = flags->precision;
	if (flags->width > len)
	{
		flags->width = flags->width - len;
		ft_putchar_printf(flags->width, ' ', flags);
	}
	while (str[i] && i < len)
		ft_putchar_printf(1, str[i++], flags);
	if (flags->left > len)
	{
		flags->left -= len;
		ft_putchar_printf(flags->left, ' ', flags);
	}
}
