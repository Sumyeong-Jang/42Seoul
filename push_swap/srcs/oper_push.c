/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:46:33 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 13:46:35 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static t_node	*pop(t_info *info)
{
	t_node	*tmp;

	tmp = NULL;
	if (!info->size)
		return (tmp);
	tmp = info->top;
	if (info->size == 1)
	{
		info->top = NULL;
		info->bottom = NULL;
		info->size -= 1;
		return (tmp);
	}
	info->top = info->top->next;
	info->top->prev = info->bottom;
	info->bottom->next = info->top;
	info->size -= 1;
	return (tmp);
}

void	pa(t_stack *stack)
{
	t_node	*tmp;

	tmp = pop(stack->b);
	if (!tmp)
		return ;
	push(stack->a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_node	*tmp;

	tmp = pop(stack->a);
	if (!tmp)
		return ;
	push(stack->b, tmp);
	write(1, "pb\n", 3);
}
