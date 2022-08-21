NAME	=	philo

CC		=	cc
CFLAG	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	srcs/main_bonus.c srcs/philo_utils_bonus.c srcs/init_bonus.c srcs/utils_bonus.c
OBJS	=	$(SRCS:.c=.o)

.c.o	:
	$(CC) $(CFLAGS) -c -o $*.o $<

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lpthread -g

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re