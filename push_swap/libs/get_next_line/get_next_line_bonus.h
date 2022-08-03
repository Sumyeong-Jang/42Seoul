/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:14:31 by sumjang           #+#    #+#             */
/*   Updated: 2022/04/14 22:20:35 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*get_node(t_list *head, int fd);
char	*read_input(char **backup, int fd);
char	*split_line(char const *backup);
size_t	save_remains(t_list **node, size_t len);
void	del_node(t_list **node);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*new_ft_strjoin(char const *backup, char const *buf);

#endif
