/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:08:52 by sumjang           #+#    #+#             */
/*   Updated: 2022/04/14 22:20:23 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
char	*new_ft_strjoin(char const *backup, char const *buf);

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	find = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (find == 0)
		return ((char *)s + i);
	return (0);
}

char	*new_ft_strjoin(char const *backup, char const *buf)
{
	char	*new;

	if (buf == NULL)
		return (NULL);
	else if (backup == NULL && buf)
	{
		new = malloc(ft_strlen(buf) + 1);
		if (new == NULL)
			return (NULL);
		ft_strlcpy(new, buf, ft_strlen(buf) + 1);
		return (new);
	}
	new = (char *)malloc(sizeof(char) * \
	(ft_strlen(backup) + ft_strlen(buf) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, backup, ft_strlen(backup) + 1);
	ft_strlcpy(new + ft_strlen(backup), buf, ft_strlen(buf) + 1);
	return (new);
}
