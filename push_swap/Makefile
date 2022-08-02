NAME			=	push_swap

CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar rcs
BONUS			=	checker

SRCS_UTILS		= srcs/
SRCS			=	$(SRCS_UTILS)push_swap.c \
					$(SRCS_UTILS)init.c \
					$(SRCS_UTILS)input.c \
					$(SRCS_UTILS)swap.c \
					$(SRCS_UTILS)pop_push.c \
					$(SRCS_UTILS)rotate.c \
					$(SRCS_UTILS)rotate_reverse.c \
					$(SRCS_UTILS)sort_small.c \
					$(SRCS_UTILS)sort_large.c \
					$(SRCS_UTILS)utils.c \
					$(SRCS_UTILS)finish.c
OBJ_DIR			=	./obj
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

BONUS_SRCS_UTILS=	srcs_bonus/
BONUS_SRCS		=	$(BONUS_SRCS_UTILS)checker.c \
					$(BONUS_SRCS_UTILS)init.c \
					$(BONUS_SRCS_UTILS)input.c \
					$(BONUS_SRCS_UTILS)swap.c \
					$(BONUS_SRCS_UTILS)pop_push.c \
					$(BONUS_SRCS_UTILS)rotate.c \
					$(BONUS_SRCS_UTILS)rotate_reverse.c \
					$(BONUS_SRCS_UTILS)utils.c \
					$(BONUS_SRCS_UTILS)get_next_line.c \
					$(BONUS_SRCS_UTILS)finish.c
BONUS_OBJS		=	$(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

LIBFT_DIR		=	libs/libft
LIBFT_LIB		=	$(LIBFT_DIR)/libft.a

all				:	$(NAME)

bonus			:	$(BONUS)

$(NAME)			:	$(OBJS)
	make all -C $(LIBFT_DIR)
	cc $(CFLAGS) -I./$(OBJS) -L./$(LIBFT_DIR) -l$(LIBFT_LIB) -o $@

$(BONUS)		:	$(BONUS_OBJS)
	make all -C $(LIBFT_DIR)
	cc $(CFLAGS) -I./$(BONUS_OBJS) -L./$(LIBFT_DIR) -l$(LIBFT_LIB) -o $@

$(OBJ_DIR)/%.o	:	%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@ -g

$(LIBFT)		:
	make -C $(LIBFT_DIR) all

clean			:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean			:	clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT_DIR)

re				:	fclean all

.PHONY			:	all clean fclean re bonus