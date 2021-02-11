/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:14:10 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/11 15:15:06 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_parse_flags(const char *format, t_list *flags)
{
	int i;
	int atoi;
	i = 0;
	atoi = 0;

	while (ft_is_in_charset(format[i], "0123456789"))
	{
		atoi = atoi * 10 + format[i] - 48;
		i++;
	}
	flags->width = atoi;
	atoi = 0;
	if(format[i] == '.')
	{
		i++;
		while (ft_is_in_charset(format[i], "0123456789"))
		{
			atoi = atoi * 10 + format[i] - 48;
			i++;
		}
		flags->precision = atoi;
	}
	return (i);
}
