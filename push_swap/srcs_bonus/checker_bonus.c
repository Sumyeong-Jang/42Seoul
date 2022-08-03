/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:58:47 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 20:58:49 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	execute(t_stack *stack);
static void	cmd_execute(t_stack *stack, const char *cmd);
static void	check(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->a = get_stack_a(argc, argv);
	stack->b = init_info();
	execute(stack);
	check(stack);
	free_t_lists(stack);
	return (0);
}

static void	execute(t_stack *stack)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		cmd_execute(stack, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
}

static void	cmd_execute(t_stack *stack, const char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(stack, 1);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(stack, 1);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(stack, 1);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(stack, 1);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(stack, 1);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(stack, 1);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(stack, 1);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(stack, 1);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(stack, 1);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(stack, 1);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(stack, 1);
	else
		ft_exit(NULL);
}

static void	check(t_stack *stack)
{
	if (is_sorted(stack->a) && stack->b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
