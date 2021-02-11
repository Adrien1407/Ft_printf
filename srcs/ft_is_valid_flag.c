/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:11:58 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/11 15:35:55 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_is_valid_flag(const char *format, t_list *flags)
{
	int i;

	i = 1;
	flags->precision = 0;
	flags->width = 0;
	flags->id = 0;

	i += ft_parse_flags(&format[i], flags);
	if (ft_is_in_charset(format[i], "sdx"))
	{
		flags->id = format[i++];
		return(i);
	}
	return (0);
}
