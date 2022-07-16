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
GNL_UTILS = get_next_line/
SRCS		= main.c map_setting.c img_setting.c key_setting.c utils.c \
				$(LIBFT_UTILS)ft_putendl_fd.c \
				$(LIBFT_UTILS)ft_split.c \
				$(LIBFT_UTILS)ft_strdup.c \
				$(LIBFT_UTILS)ft_strjoin.c \
				$(LIBFT_UTILS)ft_strlcat.c \
				$(LIBFT_UTILS)ft_strlcpy.c \
				$(LIBFT_UTILS)ft_strlen.c \
				$(LIBFT_UTILS)ft_strncmp.c \
				$(LIBFT_UTILS)ft_strrchr.c \
				$(GNL_UTILS)get_next_line.c \
				$(GNL_UTILS)get_next_line_utils.c

OBJS		= $(SRCS:%.c=%.o)

%.OBJS		:	%.c
			cc $(CFLAG) -Imlx -c -o $*.o $<

$(NAME)		:	$(OBJS)
		cc $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
