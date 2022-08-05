/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:46:15 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 17:53:23 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_info		*get_stack_a(int argc, char **argv);
static void	split_input_str(const char *s, t_info *a_info);
static void	is_valid_number_n_insert(char *s, t_info *a_info);
static int	indexing_n_check_dup(t_info *a_info, t_node *node);

t_info	*get_stack_a(int argc, char **argv)
{
	t_info	*a_info;
	int		i;

	i = 1;
	a_info = init_info();
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') == NULL)
			is_valid_number_n_insert(argv[i], a_info);
		else
			split_input_str(argv[i], a_info);
		i++;
	}
	return (a_info);
}

static void	split_input_str(const char *s, t_info *a_info)
{
	char	**input_num;
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		ft_exit("Error\n");
	input_num = ft_split(s, ' ');
	if (!input_num)
		ft_exit("Error\n");
	i = 0;
	while (input_num[i] != NULL)
	{
		is_valid_number_n_insert(input_num[i], a_info);
		free(input_num[i]);
		i++;
	}
	free(input_num);
}

static void	is_valid_number_n_insert(char *s, t_info *a_info)
{
	long long	num;
	t_node		*new_node;
	char		*tmp;

	if (*s == '\0')
		ft_exit("Error\n");
	if (!(ft_is_num(s)))
		ft_exit("Error\n");
	tmp = s;
	while (*tmp == '0')
		tmp++;
	if (ft_strlen(tmp) > 11)
		ft_exit("Error\n");
	num = ft_atoll(tmp);
	if (num > 2147483647 || num < -2147483648)
		ft_exit("Error\n");
	new_node = init_node((int)num);
	if (!indexing_n_check_dup(a_info, new_node))
		ft_exit("Error\n");
	push(a_info, new_node);
	rotate(a_info);
}

static int	indexing_n_check_dup(t_info *a_info, t_node *node)
{
	t_node	*head;

	if (a_info->size == 0)
		return (1);
	head = a_info->top;
	while (1)
	{
		if (head->data < node->data)
			node->index++;
		else if (head->data > node->data)
			head->index++;
		else
			return (0);
		head = head->next;
		if (head == a_info->top)
			break ;
	}
	return (1);
}
