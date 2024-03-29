/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:59:09 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 20:59:11 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_exit(char *message)
{
	if (message != NULL)
		perror(message);
	exit(EXIT_FAILURE);
}

void	free_t_list(t_info *info)
{
	t_node	*tmp;

	if (info->size)
	{
		info->bottom->next = NULL;
		info->bottom = NULL;
		while (1)
		{
			tmp = info->top;
			info->top = info->top->next;
			free(tmp);
			if (!info->top)
				break ;
		}
	}
	free(info);
}

void	free_t_lists(t_stack *stack)
{
	free_t_list(stack->a);
	free_t_list(stack->b);
	free(stack);
}
