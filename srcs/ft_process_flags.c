/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:08:35 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 21:23:20 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_process_flags(t_list *flags)
{
	if (ft_is_in_charset(flags->id, "duixXp"))
	{
		if (((flags->zero) && ((flags->precision > 0)
						|| (flags->precision == -1))))
		{
			flags->width = flags->zero;
			flags->zero = 0;
		}
	}
	if (flags->width < 0)
	{
		flags->left = -flags->width;
		flags->width = 0;
	}
	if (flags->zero < 0)
	{
		flags->left = -flags->zero;
		flags->zero = 0;
	}
	if (flags->left < 0)
		flags->left = -flags->left;
	if (flags->precision < -1)
		flags->precision = 0;
}
