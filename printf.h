/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienlanlan <adlancel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:00:02 by adrienlan         #+#    #+#             */
/*   Updated: 2021/01/08 16:04:11 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	PRINTF_H
# define PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_count_digits(long int n);
int				ft_atoi(const char *str);
void			ft_putnbr_base(int nbr, char *base);
int				checkbase(char *base);
size_t			ft_strlen(const char *s);
void			ft_putnbr(int c);
int				ft_count_digits(long int n);
int				ft_atoi(const char *str);
void			ft_putchar(int c);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr(const char *s);
void			ft_putstr_fd(const char *s, int fd);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
#endif
