/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:16:49 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/16 16:33:37 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_print_argument(va_list ap, t_list *flags)
{
	int id;
	
	id = flags->id;
	if (id == 's')
		ft_printf_putstr(va_arg(ap, char*), flags);
	if (id == 'd')
		ft_putnbr(va_arg(ap, int), flags);
	if (id == 'i')
		ft_putnbr(va_arg(ap, int), flags);
	if (id == 'u')
		ft_putnbr(va_arg(ap, unsigned int), flags);
	if (id == 'c')
		ft_printf_char(va_arg(ap, int), flags);
}
