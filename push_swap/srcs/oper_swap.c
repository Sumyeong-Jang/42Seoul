#include "../include/push_swap.h"

static void	swap(t_info *info)
{
	int	tmp_num;
	int	tmp_index;

	if (info->size < 2)
		return ;
	tmp_num = info->top->num;
	info->top->num = info->top->next->num;
	info->top->next->num = tmp_num;
	tmp_index = info->top->index;
	info->top->index = info->top->next->index;
	info->top->next->index = tmp_index;
}

void	sa(t_stack *stack, int isChecker)
{
	swap(stack->a);
	if (!isChecker)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int isChecker)
{
	swap(stack->b);
	if (!isChecker)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int isChecker)
{
	swap(stack->a);
	swap(stack->b);
	if (!isChecker)
		write(1, "ss\n", 3);
}