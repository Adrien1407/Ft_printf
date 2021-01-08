# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 15:52:08 by adlancel          #+#    #+#              #
#    Updated: 2020/12/04 14:20:00 by adlancel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	ft_strlen.c ft_isalnum.c ft_putnbr.c ft_putnbr_fd.c \
					ft_count_digits.c ft_atoi.c ft_isdigit.c ft_putchar.c \
					ft_putchar_fd.c ft_putstr.c ft_putendl.c ft_putendl_fd.c \
					ft_putstr_fd.c ft_isalpha.c ft_islower.c ft_tolower.c \
					ft_toupper.c ft_isupper.c ft_isascii.c ft_isprint.c \
					ft_is_c.c ft_is_in_c.c  ft_itoa.c \
					ft_strcat.c ft_strncat.c ft_strlcat.c ft_count_words.c \
					ft_strjoin.c ft_bzero.c ft_split.c ft_strclr.c \
					ft_strequ.c ft_strnequ.c ft_strcpy.c ft_strncpy.c \
					ft_strlcpy.c ft_strstr.c ft_strrchr.c ft_strchr.c \
					ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_strdel.c \
					ft_strdup.c ft_strndup.c ft_strmap.c ft_strmapi.c \
					ft_substr.c ft_memcpy.c ft_memmove.c ft_memccpy.c \
					ft_calloc.c ft_memcmp.c ft_memset.c ft_memchr.c \
					ft_memalloc.c ft_memdel.c 
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstlast.c \
					ft_lstlast.c ft_lstnew.c ft_lstmap.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= clang 
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus

