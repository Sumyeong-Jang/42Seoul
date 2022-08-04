NAME			=	push_swap

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
BONUS			=	checker

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

SRCS_BONUS_UTILS= srcs_bonus/
GNL_UTILS		= libs/get_next_line/
BONUS_SRCS		=	$(SRCS_BONUS_UTILS)checker_bonus.c \
					$(SRCS_BONUS_UTILS)ft_exit_bonus.c \
					$(SRCS_BONUS_UTILS)get_stack_a_bonus.c \
					$(SRCS_BONUS_UTILS)init_bonus.c \
					$(SRCS_BONUS_UTILS)oper_push_bonus.c \
					$(SRCS_BONUS_UTILS)oper_rotate_bonus.c \
					$(SRCS_BONUS_UTILS)oper_rotate_rev_bonus.c \
					$(SRCS_BONUS_UTILS)oper_swap_bonus.c \
					$(SRCS_BONUS_UTILS)utils_bonus.c \
					$(GNL_UTILS)get_next_line.c \
					$(GNL_UTILS)get_next_line_utils.c
BONUS_OBJS		=	$(BONUS_SRCS:.c=.o)

LIBFT_DIR		=	./libs/libft
LIBFT			=	$(LIBFT_DIR)/libft.a

%.o				:	%.c
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c -o $*.o $<

all				:	$(NAME)

bonus			:	$(BONUS)

$(NAME)			:	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I ./ $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME) $(OJBS)

$(BONUS)		:	$(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT_DIR) -lft -o $(BONUS) $(BONUS_OBJS)


$(LIBFT)		:
	make -C $(LIBFT_DIR) all

clean			:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean			:	clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	$(RM) $(LIBFT_LIB)
	make -C $(LIBFT_DIR) fclean

re				:
	make fclean
	make all

.PHONY			:	all clean fclean re bonus