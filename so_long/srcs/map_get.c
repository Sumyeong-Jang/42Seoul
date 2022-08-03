/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:22:51 by sumjang           #+#    #+#             */
/*   Updated: 2022/07/20 16:27:16 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*map_get(int fd, char *lines)
{
	char	*line;
	char	*tmp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(line);
		free(tmp);
	}
	if (lines == NULL)
		ft_perror_exit("Error\n: Map is empty\n");
	if (lines[0] == '\n')
		ft_perror_exit("Error\n: Map must be rectangular\n");
	return (lines);
}
