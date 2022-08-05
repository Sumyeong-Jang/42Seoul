/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:46:51 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 13:46:53 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_info *info)
{
	int	tmp_data;
	int	tmp_index;

	if (info->size < 2)
		return ;
	tmp_data = info->top->data;
	info->top->data = info->top->next->data;
	info->top->next->data = tmp_data;
	tmp_index = info->top->index;
	info->top->index = info->top->next->index;
	info->top->next->index = tmp_index;
}

void	sa(t_stack *stack)
{
	swap(stack->a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(stack->b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	swap(stack->a);
	swap(stack->b);
	write(1, "ss\n", 3);
}
