/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:08:35 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/15 18:46:21 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_process_flags(t_list *flags)
{
	if (flags->width < 0)
	{
		flags->left = -flags->width;
		flags->width = 0;
	}
	if (flags->width && flags->precision)
	flags->width = flags->width - flags->precision;
	printf("%d", flags->width);
	if (flags->left && flags->precision)
	flags->left = flags->left - flags->precision;
}
