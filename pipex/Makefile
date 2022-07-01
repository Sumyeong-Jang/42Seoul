# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 13:50:15 by sumjang           #+#    #+#              #
#    Updated: 2022/06/27 13:50:20 by sumjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= gcc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar rcs

D_UTILS	= libft/
SRCS	= main.c pipex.c ft_exit.c \
			$(D_UTILS)ft_split.c \
			$(D_UTILS)ft_strdup.c \
			$(D_UTILS)ft_strjoin.c \
			$(D_UTILS)ft_strlcat.c \
			$(D_UTILS)ft_strlcpy.c \
			$(D_UTILS)ft_strlen.c \
			$(D_UTILS)ft_strncmp.c

OBJS	= $(SRCS:.c=.o)

%.o		:  %.c
		$(CC) $(CFLAG) -c -o $*.o $<

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all		: $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
