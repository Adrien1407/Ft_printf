/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:08:35 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/16 13:59:42 by adlancel         ###   ########.fr       */
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
}
