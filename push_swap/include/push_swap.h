#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
	int				index;
}	t_node;

typedef struct s_info {
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}	t_info;

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}	t_stack;

t_node		*init_node(int num);
t_list		*init_info(void);
t_info		*get_stack_a(int argc, char *argv[]);
int			is_sorted(t_list *list);
void		sort_small(t_lists *lists);
void		sort_large(t_lists *lists);
int			is_rotate(t_list *list, int standard);
int			get_top(t_list *list);
int			ft_isnum(const char *s);
long long	ft_atoll(const char *str);
int			ft_numlen(long long n);
void		error_exit(void);
void		free_t_lists(t_lists *lists);
void		push(t_list *list, t_node *node);
void		rotate(t_list *list);
void		sa(t_lists *lists, int isChecker);
void		sb(t_lists *lists, int isChecker);
void		ss(t_lists *lists, int isChecker);
void		pa(t_lists *lists, int isChecker);
void		pb(t_lists *lists, int isChecker);
void		ra(t_lists *lists, int isChecker);
void		rb(t_lists *lists, int isChecker);
void		rr(t_lists *lists, int isChecker);
void		rra(t_lists *lists, int isChecker);
void		rrb(t_lists *lists, int isChecker);
void		rrr(t_lists *lists, int isChecker);

#endif