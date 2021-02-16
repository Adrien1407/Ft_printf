/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:11:58 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/16 16:01:45 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_is_valid_flag(const char *format, t_list *flags)
{
	int i;

	i = 1;

	i += ft_parse_flags(&format[i], flags);
	if (ft_is_in_charset(format[i], "sdxXicup"))
	{
		flags->id = format[i++];
		return(i);
	}
	return (0);
}
