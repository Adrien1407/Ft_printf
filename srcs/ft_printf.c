/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:57:31 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/12 18:40:21 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_printf(const char *format, ...)
{
	int i;
	t_list *flags;
	va_list ap;
	int j;

	i = 0;
	flags = malloc(sizeof(t_list));
	if (!flags)
		return (0);
	va_start(ap, format);
	flags->precision = -0;
	flags->width = 0;
	flags->id = 0;
	flags->left = 0;
	flags->written = 0;
	while (format[i])
	{
		j = 0;
		if (format[i] == '%' && format[i + 1])
		{
			j = ft_is_valid_flag(&format[i], flags);
			if (j)
			{
				ft_print_argument(ap, flags);
				i += j;
			}
			else
				ft_putchar_printf(format[i++], flags);
		}
		else  
			ft_putchar_printf(format[i++], flags);
	}
	free(flags);
	va_end(ap);
	return (0);
}
