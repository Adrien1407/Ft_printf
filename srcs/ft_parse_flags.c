/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:14:10 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 21:16:20 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_parse_flags(const char *format, va_list ap, t_list *flags)
{
	int i;

	i = 0;
	i += ft_parse_zero_width(&format[i], flags);
	i += ft_parse_wildcard(&format[i], ap, flags);
	i += ft_parse_precision(&format[i], ap, flags);
	return (i);
}
