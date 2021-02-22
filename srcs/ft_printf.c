/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:57:31 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/22 21:23:02 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	ft_printf_bis(const char *format, va_list ap, t_list *flags)
{
	int i;
	int j;

	i = 0;
	while (format[i])
	{
		j = 0;
		if (format[i] == '%' && format[i + 1])
		{
			j = ft_is_valid_flag(&format[i], ap, flags);
			if (j)
			{
				ft_print_argument(ap, flags);
				i += j;
			}
			else
				ft_putchar_printf(1, format[i++], flags);
		}
		else
			ft_putchar_printf(1, format[i++], flags);
	}
}

int			ft_printf(const char *format, ...)
{
	t_list	*flags;
	va_list	ap;
	int		ret;

	flags = malloc(sizeof(t_list));
	if (!flags)
		return (0);
	ft_init_flags(flags);
	va_start(ap, format);
	flags->written = 0;
	ft_printf_bis(format, ap, flags);
	ret = flags->written;
	free(flags);
	va_end(ap);
	return (ret);
}
