/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:46:20 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 13:46:25 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_info	*init_info(void);
t_node	*init_node(int num);
int		is_sorted(t_info *info);

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		ft_exit("Error\n");
	info->top = NULL;
	info->bottom = NULL;
	info->size = 0;
	return (info);
}

t_node	*init_node(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		ft_exit("Error\n");
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
