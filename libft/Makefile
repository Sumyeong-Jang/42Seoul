# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 17:23:57 by sumjang           #+#    #+#              #
#    Updated: 2022/02/09 01:00:34 by sumjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		  ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus:
	@make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
