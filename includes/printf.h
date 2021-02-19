/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienlanlan <adlancel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:00:02 by adrienlan         #+#    #+#             */
/*   Updated: 2021/02/19 15:24:00 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef	struct	s_list
{
	int precision;
	int left;
	int zero;
	int width;
	int id;
	int written;
}				t_list;
void			ft_process_flags(t_list *flags);
void			ft_init_flags(t_list *flags);
void			ft_printf_char(const char c, t_list *flags);
int				ft_parse_flags(const char *format, va_list ap, t_list *flags);
int				ft_is_valid_flag(const char *format, va_list ap,  t_list *flags);
void			ft_print_argument(va_list ap, t_list *flags);
int				ft_is_in_charset(char c, char *str);
int				ft_count_digits(long int n);
int				ft_count_hexa(long int n);
int				ft_count_address(long int n);
size_t			ft_strlen(const char *s);
void			ft_putnbr(long c, t_list *flags);
void			ft_putnbr_recursive(long c, t_list *flags);
void			ft_putnbr_base2(long c, t_list *flags);
void			ft_putnbr2(long c, t_list *flags);
void			ft_putnbr_base_address(long c, t_list *flags);
void			ft_putnbr3(long c, t_list *flags);
void			ft_putchar_printf(int c, t_list *flags);
void			ft_printf_putstr(const char *s, t_list *flags);
int				ft_printf(const char *format, ...);
#endif
