# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:59:54 by sumjang           #+#    #+#              #
#    Updated: 2022/07/13 15:59:55 by sumjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CFLAG		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

LIBFT_UTILS	= libft/
SRCS		= main.c map_setting.c img_setting.c key_setting.c\
				ft_perror_exit.c ft_pstr_exit.c
				$(LIBFT_UTILS)



OBJS		= $(SRCS:%.c=%.o)

%.OBJS		:	%.c
			cc $(CFLAG) -c -o $*.o $<

$(NAME)		:	$(OBJS)
		cc $(CFLAGS) -o $(NAME) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit

all			:	$(NAME)

clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
