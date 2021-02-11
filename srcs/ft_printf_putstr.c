/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:15:48 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/11 15:34:21 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_printf_putstr(const char *str, t_list *flags)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	if (flags->precision < len)
		len = flags->precision;
	if (flags->width > len)
	{
		flags->width = flags->width - len;
		while(flags->width)
		{
			write(1, " ", 1);
			flags->width--;
		}
	}
	while (str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}

}
