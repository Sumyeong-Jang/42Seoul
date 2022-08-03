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
LIBFT		= libs/libft

CFLAG		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

SRCS_UTILS = srcs/
SRCS_BONUS_UTILS = srcs_bonus/
GNL_UTILS = libs/get_next_line/
SRCS		= $(SRCS_UTILS)main.c $(SRCS_UTILS)map_setting.c \
				$(SRCS_UTILS)img_setting.c $(SRCS_UTILS)key_setting.c \
				$(SRCS_UTILS)map_get.c \
				$(SRCS_UTILS)utils.c \
				$(GNL_UTILS)get_next_line.c \
				$(GNL_UTILS)get_next_line_utils.c

OBJS		= $(SRCS:%.c=%.o)
LIBFT_LIB	= $(LIBFT)/libft.a

%.o		:	%.c
			cc $(CFLAG) -Imlx -c -o $*.o $<

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)
		cc $(CFLAGS) -L./$(LIBFT) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

clean		:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re
