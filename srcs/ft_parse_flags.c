/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:14:10 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/19 15:25:24 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_parse_flags(const char *format, va_list ap, t_list *flags)
{
	int i;
	int atoi;
	i = 0;
	atoi = 0;

	ft_init_flags(flags);
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			flags->left = 1;
			flags->zero = 0;
		}
		if (format[i] == '0' && !flags->left)
			flags->zero = 1;
		i++;
	}
	if (format[i] == '*')
	{
		if (flags->left)
			flags->left = va_arg(ap, int);
		else if (flags->zero)
			flags->zero = va_arg(ap, int);
		else
			flags->width = va_arg(ap, int);
		i++;
	}
	else 
	{
		while (ft_is_in_charset(format[i], "0123456789"))
		{
			atoi = atoi * 10 + format[i] - 48;
			i++;
		}
		if (flags->left)
			flags->left = atoi;
		else if (flags->zero)
			flags->zero = atoi;
		else 
			flags->width = atoi;
	}
	atoi = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			i++;
			flags->precision = va_arg(ap, int);
		}
		else 
		{
			while (ft_is_in_charset(format[i], "0123456789"))
			{
				atoi = atoi * 10 + format[i] - 48;
				i++;
			}
			flags->precision = atoi;
		}
		if (flags->precision == -1)
			flags->precision = -2;
		if (flags->precision == 0)
			flags->precision = -1;
	}
	ft_process_flags(flags);
	return (i);
}
