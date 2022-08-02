#include "../include/push_swap.h"

void	push(t_info *info, t_node *node)
{
	if (info->size == 0)
	{
		node->next = node;
		node->prev = node;
		info->top = node;
		info->bottom = node;
	}
	else
	{
		node->next = info->top;
		node->prev = info->bottom;
		info->top->prev = node;
		info->bottom->next = node;
		info->top = node;
	}
	info->size += 1;
}

static t_node	*pop(t_list *list)
{
	t_node	*tmp;

	tmp = NULL;
	if (!list->size)
		return (tmp);
	tmp = list->top;
	if (list->size == 1)
	{
		list->top = NULL;
		list->bottom = NULL;
		list->size -= 1;
		return (tmp);
	}
	list->top = list->top->next;
	list->top->prev = list->bottom;
	list->bottom->next = list->top;
	list->size -= 1;
	return (tmp);
}

void	pa(t_lists *lists, int isChecker)
{
	t_node	*tmp;

	tmp = pop(lists->b);
	if (!tmp)
		return ;
	push(lists->a, tmp);
	if (!isChecker)
		write(1, "pa\n", 3);
}

void	pb(t_lists *lists, int isChecker)
{
	t_node	*tmp;

	tmp = pop(lists->a);
	if (!tmp)
		return ;
	push(lists->b, tmp);
	if (!isChecker)
		write(1, "pb\n", 3);
}