/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:57:31 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/19 15:23:47 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_printf(const char *format, ...)
{
	int i;
	t_list *flags;
	va_list ap;
	int j;
	int ret;

	i = 0;
	flags = malloc(sizeof(t_list));
	if (!flags)
		return (0);
	va_start(ap, format);
ft_init_flags(flags);
	flags->written = 0;
	while (format[i])
	{
		j = 0;
		if (format[i] == '%' && format[i + 1])
		{
			j = ft_is_valid_flag(&format[i], ap,  flags);
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
	ret = flags->written;
	free(flags);
	va_end(ap);
	return (ret);
}
/*int main()
{
ft_printf("%-*s\n", 32,  "abc");
printf("%-*s", 32, "abc");
}
*/
