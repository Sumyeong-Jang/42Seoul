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
static void	raise_b_last_index(t_stack *stack);

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
		if (get_top(stack->a) <= i)
		{
			pb(stack, 0);
			i++;
		}
		else if (get_top(stack->a) > i && get_top(stack->a) <= i + chunk)
		{
			pb(stack, 0);
			rb(stack, 0);
			i++;
		}
		else
		{
			if (rotate_or_reverse(stack->a, i + chunk))
				ra(stack, 0);
			else
				rra(stack, 0);
		}
	}
}

static void	b_to_a(t_stack *stack)
{
	while (stack->b->size != 0)
	{
		raise_b_last_index(stack);
		pa(stack, 0);
	}
}

static void	raise_b_last_index(t_stack *stack)
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
			rb(stack, 0);
	else
		while (stack->b->top != tmp)
			rrb(stack, 0);
}
