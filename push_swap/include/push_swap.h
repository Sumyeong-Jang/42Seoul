/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:47:17 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 17:16:07 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_info	*a;
	t_info	*b;
}	t_stack;

t_info		*get_stack_a(int argc, char **argv);

t_info		*init_info(void);
t_node		*init_node(int num);
int			is_sorted(t_info *info);

void		ft_exit(char *message);
void		free_stack(t_stack *stack);
void		free_stack_a(t_stack *stack);

long long	ft_atoll(const char *str);
int			ft_is_num(const char *s);
int			top_index(t_info *info);

void		sort_small(t_stack *stack);
int			rotate_or_reverse(t_info *info, int n);

void		sort_large(t_stack *stack);

void		push(t_info *info, t_node *node);
void		pa(t_stack *stack);
void		pb(t_stack *stack);

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);

void		rotate(t_info *info);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);

void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

#endif
