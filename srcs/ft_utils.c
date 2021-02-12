/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:50:25 by adlancel          #+#    #+#             */
/*   Updated: 2021/02/12 18:17:51 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_digits(long int n)
{
	int			i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_is_in_charset(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
void	ft_putchar_printf(int c, t_list *flags)
{
	write(1, &c, 1);
	flags->written++;
}

void	ft_process_flags(t_list *flags)
{
	if (flags->width < 0)
	{
		flags->left = -flags->width;
		flags->width = 0;
	}
}
