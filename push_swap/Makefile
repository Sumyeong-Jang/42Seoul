NAME			=	push_swap

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

SRCS_UTILS		= srcs/
SRCS			=	$(SRCS_UTILS)ft_exit.c \
					$(SRCS_UTILS)get_stack_a.c \
					$(SRCS_UTILS)init.c \
					$(SRCS_UTILS)push_swap.c \
					$(SRCS_UTILS)oper_push.c \
					$(SRCS_UTILS)oper_rotate_rev.c \
					$(SRCS_UTILS)oper_rotate.c \
					$(SRCS_UTILS)oper_swap.c \
					$(SRCS_UTILS)sort_large.c \
					$(SRCS_UTILS)sort_small.c \
					$(SRCS_UTILS)utils.c
OBJS			=	$(SRCS:.c=.o)

LIBFT_DIR		=	./libs/libft
LIBFT			=	$(LIBFT_DIR)/libft.a

%.o				:	%.c
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c -o $*.o $<

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I ./ $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME) $(OJBS)

$(LIBFT)		:
	make -C $(LIBFT_DIR) all

clean			:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean			:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	make -C $(LIBFT_DIR) fclean

re				:
	make fclean
	make all

.PHONY			:	all clean fclean re