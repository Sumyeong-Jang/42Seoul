# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:25:13 by sumjang           #+#    #+#              #
#    Updated: 2022/05/26 17:48:52 by sumjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar rcs

SRCS	= ft_printf.c ft_printf_utils.c
OBJS	= $(SRCS:.c=.o)

%.o		:  %.c
		$(CC) $(CFLAG) -c -o $*.o $<

$(NAME)	: $(OBJS)
	@ $(AR) $(NAME) $(OBJS)
all		: $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:
		$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
