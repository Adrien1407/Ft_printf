/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:04:28 by adlancel          #+#    #+#             */
/*   Updated: 2021/01/08 17:21:39 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"

int ft_printf(char *format, ...)
{
	va_list parametersInfo;
	int atoi = 0;
	int i = 0;
	int j = 0;
	va_start(parametersInfo, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			while ((format[i + j] >= 0) && (format[i + j] <= 9))
				{
					j++;
				}
	
		format += i;
			if (format[i] == 's')
				ft_putstr(va_arg(parametersInfo, char *));
			if (format[i] == 'd')
			{ 
				ft_putnbr(va_arg(parametersInfo, int));
			if (format[i] == 'i')
				ft_putnbr(va_arg(parametersInfo, int));
			if (format[i] == 'p')
				ft_putnbr(va_arg(parametersInfo, int));
			if (format[i] == 'c')
				ft_putchar(va_arg(parametersInfo, int));
			if (format[i] == 'x') // hexa
				ft_putnbr_base(va_arg(parametersInfo, int), "0123456789abcdef");
			if (format[i] == 'X') // hexa
				ft_putnbr_base(va_arg(parametersInfo, int), "0123456789ABCDEF");
			if (format[i] == 'X') // HEXA
				ft_putchar(va_arg(parametersInfo, int));
			if (format[i] == 'u')
				ft_putnbr(va_arg(parametersInfo, int)); // a modifier pour unsigned
		}
		else 
			ft_putchar(format[i]);
		i++;;
	}
	va_end(parametersInfo);
	return (0);
}


int main()
{
	char hello = 'c';
	int  hello1 = 14;
	char hello2[6] = "string";
	int  hexa = 234;
	int  HEXA = 234;
	ft_printf("Ceci est une %10s\n Ceci est l'entier %d\nCeci est le caractere %c\nCeci est un hexa %x\nCeci est un HEXA %X\n", hello2, hello1, hello, hexa, HEXA);
}
