/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:00:25 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/03 21:00:27 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_info		*get_stack_a(int argc, char *argv[]);
static void	is_valid_number_n_insert(const char *s, t_info *a_info);
static int	indexing_n_is_unique(t_info *a_info, t_node *node);
static void	split_input_str(const char *s, t_info *a_info);

t_info	*get_stack_a(int argc, char *argv[])
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

static void	is_valid_number_n_insert(const char *s, t_info *a_info)
{
	long long	num;
	t_node		*new_node;

	if (*s == '\0')
		ft_exit("Error\n");
	num = ft_atoll(s);
	if (!(ft_is_num(s)))
		ft_exit("Error\n");
	if (num > 2147483647 || num < -2147483648)
		ft_exit("Error\n");
	new_node = init_node((int)num);
	//push 안했는데 head->data == node->data 가능?
	if (indexing_n_is_unique(a_info, new_node))
		ft_exit("Error\n");
	push(a_info, new_node);
	rotate(a_info);//push bottom 했을 경우 rotate 해줌
}

static int	indexing_n_is_unique(t_info *a_info, t_node *node)
{
	t_node	*head;

	if (a_info->size == 0)
		return (0);
	head = a_info->top;
	while (1)
	{
		if (head->data < node->data)
			node->index++;
		else if (head->data > node->data)
			head->index++;
		else
			return (1);
		/*
		if (head == a_info->bottom)
			return (1);
		*/
		head = head->next;
		if (head == a_info->top)
			break ;
	}
	return (0);
}

static void	split_input_str(const char *s, t_info *a_info)
{
	char	**input_num;
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		ft_exit(NULL);
	input_num = ft_split(s, ' ');
	if (!input_num)
		exit(EXIT_FAILURE);
	i = 0;
	while (input_num[i] != NULL)
	{
		is_valid_number_n_insert(input_num[i], a_info);
		free(input_num[i]);
		i++;
	}
	free(input_num);
}
