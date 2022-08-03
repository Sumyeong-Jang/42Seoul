/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate_rev_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:01:22 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 21:01:23 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_reverse(t_info *info)
{
	if (info->size < 2)
		return ;
	info->bottom = info->bottom->prev;
	info->top = info->top->prev;
}

void	rra(t_stack *stack, int isChecker)
{
	rotate_reverse(stack->a);
	if (!isChecker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int isChecker)
{
	rotate_reverse(stack->b);
	if (!isChecker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int isChecker)
{
	rotate_reverse(stack->a);
	rotate_reverse(stack->b);
	if (!isChecker)
		write(1, "rrr\n", 4);
}
