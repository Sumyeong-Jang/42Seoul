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
static void	sort_three(t_stack *stack, int first, int second, int third);
static void	min_data_pop(t_stack *stack);
int			rotate_or_reverse(t_info *info, int standard);

void	sort_small(t_stack *stack)
{
	if (stack->a->size < 2)
		return ;
	else if (stack->a->size == 2)
		sort_2_nodes(stack);
	else if (stack->a->size == 3)
		sort_3_nodes(stack);
	else
	{
		min_data_pop(stack);
	}
}

static void	sort_2_nodes(t_stack *stack)
{
	t_info	*a_info;

	a_info = stack->a;
	if (a_info->top->index > a_info->top->next->index)
		sa(stack, 0);
}

static void	sort_3_nodes(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->a->top->index;
	second = stack->a->top->next->index;
	third = stack->a->top->next->next->index;
	sort_three(stack, first, second, third);
}

static void	sort_three(t_stack *stack, int first, int second, int third)
{
	if (first < second)
	{
		if (second > third && first < third)
		{
			rra(stack, 0);
			sa(stack, 0);
		}
		else if (second > third && first > third)
			rra(stack, 0);
	}
	else
	{
		if (second < third && first < third)
			sa(stack, 0);
		else if (second < third && first > third)
			ra(stack, 0);
		else if (second > third && first > third)
		{
			ra(stack, 0);
			sa(stack, 0);
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
				ra(stack, 0);
		else
			while (a_info->top->index != a_min_index)
				rra(stack, 0);
		pb(stack, 0);
		a_min_index++;
	}
	sort_3_nodes(stack);
	if (b_info->top->index < b_info->top->next->index)
		rb(stack, 0);
	while (b_info->size)
		pa(stack, 0);
}

int	rotate_or_reverse(t_info *info, int standard)//standard보다는 pivot
{
	t_node	*tmp;
	int		h_location;

	tmp = info->top;
	h_location = 0;
	while (tmp->index > standard)
	{
		tmp = tmp->next;
		h_location++;
	}
	if (h_location < info->size / 2)
		return (1);
	else
		return (0);
}
