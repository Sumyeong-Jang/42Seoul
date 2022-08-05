/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:46:08 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 13:46:12 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_stack(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		ft_exit("Error\n");
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ft_exit("Error\n");
	stack->a = get_stack_a(argc, argv);
	if (is_sorted(stack->a))
	{
		free_stack_a(stack);
		exit(EXIT_SUCCESS);
	}
	stack->b = init_info();
	sort_stack(stack);
	free_stack(stack);
	return (0);
}

static void	sort_stack(t_stack *stack)
{
	if (stack->a->size <= 5)
		sort_small(stack);
	else
		sort_large(stack);
}
