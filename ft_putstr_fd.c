/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:51:59 by adlancel          #+#    #+#             */
/*   Updated: 2021/01/08 15:14:16 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}
