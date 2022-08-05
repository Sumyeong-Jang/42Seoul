/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:47:06 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 13:47:06 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		sort_small(t_stack *stack);
static void	sort_2_nodes(t_stack *stack);
static void	sort_3_nodes(t_stack *stack);
static void	sort_three(t_stack *stack, int i1, int i2, int i3);
static void	min_data_pop(t_stack *stack);

void	sort_small(t_stack *stack)
{
	if (stack->a->size < 2)
		return ;
	else if (stack->a->size == 2)
		sort_2_nodes(stack);
	else if (stack->a->size == 3)
		sort_3_nodes(stack);
	else
		min_data_pop(stack);
}

static void	sort_2_nodes(t_stack *stack)
{
	t_info	*a_info;

	a_info = stack->a;
	if (a_info->top->index > a_info->top->next->index)
		sa(stack);
}

static void	sort_3_nodes(t_stack *stack)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = stack->a->top->index;
	i2 = stack->a->top->next->index;
	i3 = stack->a->top->next->next->index;
	sort_three(stack, i1, i2, i3);
}

static void	sort_three(t_stack *stack, int i1, int i2, int i3)
{
	if (i1 < i2)
	{
		if (i2 > i3 && i1 < i3)
		{
			rra(stack);
			sa(stack);
		}
		else if (i2 > i3 && i1 > i3)
			rra(stack);
	}
	else
	{
		if (i2 < i3 && i1 < i3)
			sa(stack);
		else if (i2 < i3 && i1 > i3)
			ra(stack);
		else if (i2 > i3 && i1 > i3)
		{
			ra(stack);
			sa(stack);
		}
	}
}

static void	min_data_pop(t_stack *stack)
{
	t_info	*a_info;
	t_info	*b_info;
	int		a_min_index;

	a_info = stack->a;
	b_info = stack->b;
	a_min_index = 0;
	while (a_info->size > 3)
	{
		if (rotate_or_reverse(a_info, a_info->size / 2))
			while (a_info->top->index != a_min_index)
				ra(stack);
		else
			while (a_info->top->index != a_min_index)
				rra(stack);
		pb(stack);
		a_min_index++;
	}
	sort_3_nodes(stack);
	if (b_info->top->index < b_info->top->next->index)
		rb(stack);
	while (b_info->size)
		pa(stack);
}
