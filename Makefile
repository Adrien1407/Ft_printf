#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 15:52:08 by adlancel          #+#    #+#              #
#    Updated: 2021/02/23 16:50:32 by adlancel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			= 	$(addprefix ./srcs/, ${SRCS_FILES})
SRCS_FILES		= \
					ft_printf.c \
					ft_utils.c	\
					ft_is_valid_flag.c \
					ft_print_argument.c \
					ft_putnbr.c \
					ft_putnbr_base.c \
					ft_putnbr_base_address.c \
					ft_printf_putstr.c \
					ft_parse_flags.c \
					ft_parsers.c \
					ft_process_flags.c \
					ft_printf_char.c \
					ft_init_flags.c \

OBJS			= ${SRCS:.c=.o}
%.o:%.c
					gcc -Wall -Wextra -I ./includes/ -o $@ -c $<

all:			${NAME}

${NAME}:		${OBJS}
				ar -rcs libftprintf.a ${OBJS}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ./libftprintf.a

re:				fclean all

.PHONY:			all clean fclean re bonus
