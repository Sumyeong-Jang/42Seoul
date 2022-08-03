/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:46:40 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 13:46:41 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_info *info)
{
	if (info->size < 2)
		return ;
	info->top = info->top->next;
	info->bottom = info->bottom->next;
}

void	ra(t_stack *stack, int isChecker)
{
	rotate(stack->a);
	if (!isChecker)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int isChecker)
{
	rotate(stack->b);
	if (!isChecker)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int isChecker)
{
	rotate(stack->a);
	rotate(stack->b);
	if (!isChecker)
		write(1, "rr\n", 3);
}
