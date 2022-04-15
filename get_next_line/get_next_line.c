/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:30:19 by sumjang           #+#    #+#             */
/*   Updated: 2022/04/15 14:24:57 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*read_input(char **backup, int fd);
char	*split_line(char const *backup);
size_t	save_remains(char **backup, size_t len);

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	backup = read_input(&backup, fd);
	if (backup == NULL || *backup == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	line = split_line(backup);
	if (line == NULL)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	if (save_remains(&backup, ft_strlen(line)) == 0)
		return (NULL);
	return (line);
}

char	*read_input(char **backup, int fd)
{
	char		*buf;
	ssize_t		n;
	char		*tmp;
	char		*new;

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
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, len + 1);
	return (line);
}

size_t	save_remains(char **backup, size_t len)
{
	char	*tmp;

	tmp = *backup;
	*backup = (char *)malloc(sizeof(char) * (ft_strlen(tmp + len) + 1));
	if (*backup == NULL)
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	ft_strlcpy(*backup, tmp + len, ft_strlen(tmp + len) + 1);
	free(tmp);
	tmp = NULL;
	return (1);
}
