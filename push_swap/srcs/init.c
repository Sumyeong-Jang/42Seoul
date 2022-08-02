#include "../include/push_swap.h"

t_info	*init_info(void);
t_node	*init_node(int num);
int	is_sorted(t_info *info);

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		exit(EXIT_FAILURE);
	list->top = NULL;
	list->bottom = NULL;
	list->size = 0;
	return (info);
}

t_node	*init_node(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->data = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	return (new_node);
}

int	is_sorted(t_info *info)
{
	t_node	*tmp;

	tmp = info->top;
	while (1)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
		if (tmp->next == info->top)
			return (1);
	}
}