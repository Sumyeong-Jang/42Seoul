# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 13:14:59 by sumjang           #+#    #+#              #
#    Updated: 2022/08/31 13:15:00 by sumjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc
CFLAG	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	srcs/main.c srcs/philo_utils.c srcs/init.c \
srcs/utils.c srcs/check.c srcs/routine.c
OBJS	=	$(SRCS:.c=.o)

.c.o	:
	$(CC) $(CFLAGS) -c -o $*.o $<

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lpthread

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
