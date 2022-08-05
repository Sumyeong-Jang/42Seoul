/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:47:01 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 13:47:02 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		sort_large(t_stack *stack);
static void	a_to_b(t_stack *stack, int chunk);
static void	b_to_a(t_stack *stack);
static void	max_index_to_top(t_stack *stack);
int			rotate_or_reverse(t_info *info, int n);

void	sort_large(t_stack *stack)
{
	int	x;
	int	chunk;

	x = stack->a->size;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	a_to_b(stack, chunk);
	b_to_a(stack);
}

static void	a_to_b(t_stack *stack, int chunk)
{
	int	i;

	i = 0;
	while (stack->a->size != 0)
	{
		if (top_index(stack->a) <= i)
		{
			pb(stack);
			i++;
		}
		else if (top_index(stack->a) > i && top_index(stack->a) <= i + chunk)
		{
			pb(stack);
			rb(stack);
			i++;
		}
		else
		{
			if (rotate_or_reverse(stack->a, i + chunk))
				ra(stack);
			else
				rra(stack);
		}
	}
}

static void	b_to_a(t_stack *stack)
{
	while (stack->b->size != 0)
	{
		max_index_to_top(stack);
		pa(stack);
	}
}

static void	max_index_to_top(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->b->top;
	while (tmp->index != stack->b->size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < stack->b->size / 2)
		while (stack->b->top != tmp)
			rb(stack);
	else
		while (stack->b->top != tmp)
			rrb(stack);
}

int	rotate_or_reverse(t_info *info, int n)
{
	t_node	*tmp;
	int		p;

	tmp = info->top;
	p = 0;
	while (tmp->index > n)
	{
		tmp = tmp->next;
		p++;
	}
	if (p < info->size / 2)
		return (1);
	else
		return (0);
}
