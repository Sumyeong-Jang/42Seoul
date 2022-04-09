/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:30:19 by sumjang           #+#    #+#             */
/*   Updated: 2022/04/09 21:30:20 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_next_line(int fd, char	**line);
int		is_newline(char *backup);
int		split_line(char **backup, char **line, int cut_idx);


char	get_next_line(int fd, char	**line)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;	// 이걸 size_t 로 받아야함?
	int			cut_idx;

	// 아래 if문에서 fd > OPEN_MAX 조건 추가함
	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0 || fd > OPEN_MAX))
		return (-1);
	// buf malloc 여부 확인
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
		// 옛날 save free 했는지 여부 확인
		if ((cut_idx = is_newline(save[fd])) >= 0)
			return (split_line(&save[fd], line, cut_idx));
	}
	return (return_all(&save[fd], line, read_size));
}

int	is_newline(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	split_line(char **backup, char **line, int cut_idx)
{
	char	*temp;
	int		len;

	(*backup)[cut_idx] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + cut_idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
}
