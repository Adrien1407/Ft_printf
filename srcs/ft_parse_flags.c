/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:14:10 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/12 18:42:56 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_parse_flags(const char *format, t_list *flags)
{
	int i;
	int atoi;
	i = 0;
	atoi = 0;

	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			flags->left = 1;
			flags->zero = 0;
		}
		if (format[i] == '0' && !flags->left)
		{
			flags->zero = 1;
		}
		i++;
	}
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
	atoi = 0;
	if (format[i] == '.')
	{
		i++;
		while (ft_is_in_charset(format[i], "0123456789"))
		{
			atoi = atoi * 10 + format[i] - 48;
			i++;
		}
		flags->precision = atoi;
		if (flags->precision == 0)
				flags->precision = -1;
	}
	ft_process_flags(flags);
	return (i);
}
