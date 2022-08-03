#include "../include/push_swap.h"

void	rotate(t_info *info)
{
	if (info->size < 2)
		return ;
	info->top = info->top->next;
	info->bottom = info->bottom->next;
}

void	ra(t_lists *lists, int isChecker)
{
	rotate(lists->a);
	if (!isChecker)
		write(1, "ra\n", 3);
}

void	rb(t_lists *lists, int isChecker)
{
	rotate(lists->b);
	if (!isChecker)
		write(1, "rb\n", 3);
}

void	rr(t_lists *lists, int isChecker)
{
	rotate(lists->a);
	rotate(lists->b);
	if (!isChecker)
		write(1, "rr\n", 3);
}

int	is_rotate(t_info *info, int standard)//standard보다는 pivot
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