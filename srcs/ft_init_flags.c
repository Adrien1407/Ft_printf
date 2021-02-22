/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:22:08 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 14:59:46 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_init_flags(t_list *flags)
{
	flags->precision = 0;
	flags->width = 0;
	flags->left = 0;
	flags->zero = 0;
	flags->id = 0;
}
