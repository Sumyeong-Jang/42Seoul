/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:14:20 by sumjang           #+#    #+#             */
/*   Updated: 2022/04/15 14:25:03 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
t_list	*get_node(t_list *head, int fd);
char	*read_input(char **backup, int fd);
char	*split_line(char const *backup);
size_t	save_remains(t_list **node, size_t len);

char	*get_next_line(int fd)
{
	static t_list	head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = get_node(&head, fd);
	if (node == NULL)
		return (NULL);
	node->backup = read_input(&(node->backup), fd);
	if (node->backup == NULL || *(node->backup) == '\0')
	{
		del_node(&node);
		return (NULL);
	}
	line = split_line(node->backup);
	if (line == NULL)
	{
		del_node(&node);
		return (NULL);
	}
	if (save_remains(&node, ft_strlen(line)) == 0)
		return (NULL);
	return (line);
}

t_list	*get_node(t_list *head, int fd)
{
	t_list	*node;

	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		else
			node = node->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->backup = NULL;
	node->prev = head;
	node->next = head->next;
	if (head->next)
		head->next->prev = node;
	head->next = node;
	return (node);
}

char	*read_input(char **backup, int fd)
{
	char	*buf;
	ssize_t	n;
	char	*tmp;
	char	*new;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	n = 0;
	new = *backup;
	while (new == NULL || !ft_strchr(new, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		tmp = new;
		new = new_ft_strjoin(new, buf);
		free(tmp);
	}
	free(buf);
	buf = NULL;
	if (n < 0)
		return (NULL);
	return (new);
}

char	*split_line(char const *backup)
{
	size_t	len;
	char	*line;

	if (ft_strchr(backup, '\n'))
	{
		len = ft_strchr(backup, '\n') - backup + 1;
	}
	else
	{
		len = ft_strchr(backup, '\0') - backup;
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, backup, len + 1);
	return (line);
}

size_t	save_remains(t_list **node, size_t len)
{
	char	*tmp;

	tmp = (*node)->backup;
	(*node)->backup = (char *)malloc(sizeof(char) * (ft_strlen(tmp + len) + 1));
	if ((*node)->backup == NULL)
	{
		free(tmp);
		tmp = NULL;
		del_node(node);
		return (0);
	}
	ft_strlcpy((*node)->backup, tmp + len, ft_strlen(tmp + len) + 1);
	free(tmp);
	tmp = NULL;
	return (1);
}
