/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:14:13 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/08 17:46:37 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_char(char const *s, char c);
static char		**go_split(char const *s, char c, size_t len, char **result);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	len;

	if (!s)
		return (NULL);
	len = count_char((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	go_split((char *)s, c, len, result);
	if (!result)
		free(result);
	return (result);
}

static char	**go_split(char const *s, char c, size_t len, char **result)
{
	size_t	x;
	size_t	y;
	size_t	i;
	char	*bookmark;

	x = 0;
	while (len--)
	{
		while (*s == c)
			s++;
		y = 0;
		i = 0;
		bookmark = (char *)s;
		while (*s != c && *s++)
			i++;
		result[x] = (char *)malloc(sizeof(char) * i + 1);
		while (y < i)
			result[x][y++] = *bookmark++;
		result[x][y] = 0;
		x++;
	}
	result[x] = 0;
	return (result);
}

static size_t	count_char(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c && *s)
			s++;
		if (!*s)
			break ;
		if (*s != c && *s)
		{
			cnt++;
			while (*s != c && *s)
				s++;
		}
	}
	return (cnt);
}
