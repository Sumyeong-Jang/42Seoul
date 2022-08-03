#include "../include/push_swap.h"

void	sort_small(t_stack *stack);
static void	sort_2_nodes(t_stack *stack);
static void	sort_3_nodes(t_stack *stack);

void	sort_small(t_stack *stack)
{
	if (stack->a->size < 2)
		return ;
	else if (stack->a->size == 2)
		sort_2_nodes(stack);
	else if (stack->a->size == 3)
		sort_3_nodes(stack);
	else
		sort_more_nodes(stack);
}

static void	sort_2_nodes(t_stack *stack)
{
	t_info	*a_info;

	a = stack->a;
	if (a->top->index > a->top->next->index)
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

static void	sort_more_nodes(t_stack *stack)//4일때랑 5일때 두 가지 경우
{
	t_info	*a_info;
	t_info	*b_info;
	int		a_min_index;

	a = stack->a;
	b = stack->b;
	a_min_index = 0;
	while (a->size > 3)
	{
		if (is_rotate(a, a->size / 2))
			while (a->top->index != a_min_index)
				ra(stack, 0);
		else
			while (a->top->index != a_min_index)
				rra(stack, 0);
		pb(stack, 0);
		a_min_index++;
	}
	sort_3_nodes(stack);
	if (b->top->index < b->top->next->index)
		rb(stack, 0);
	while (b->size)
		pa(stack, 0);
}