/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:43:01 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 16:50:39 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_parse_zero_width(const char *format, va_list ap, t_list *flags)
{
	int i;

	i = 0;
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
	return (i);
}

int	ft_parse_precision(const char *format, va_list ap, t_list *flags)
{
	int i;
	int atoi;

	i = 0;
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
				atoi = atoi * 10 + format[i++] - 48;
			flags->precision = atoi;
		}
		if (flags->precision == -1)
			flags->precision = -2;
		if (flags->precision == 0)
			flags->precision = -1;
	}
	return (i);
}

int	ft_parse_wildcard(const char *format, va_list ap, t_list *flags)
{
	int i;
	int atoi;

	i = 0;
	atoi = 0;
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
			atoi = atoi * 10 + format[i++] - 48;
		if (flags->left)
			flags->left = atoi;
		else if (flags->zero)
			flags->zero = atoi;
		else
			flags->width = atoi;
	}
	return (i);
}
