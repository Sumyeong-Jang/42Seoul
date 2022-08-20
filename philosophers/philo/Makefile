NAME	=	philo

CC		=	cc
CFLAG	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	srcs/main.c srcs/philosophers.c srcs/process.c srcs/utils.c
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