/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:14:13 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/08 12:34:52 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_char(char *s, char c);
static char		**play_split(char *s, char **result, char c);
static char		*ft_strndup(char *str, int len);

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_char(s, c) + 1));
	if (!result)
		return (NULL);
	play_split(s, result, c);
	return (result);
}

char	**play_split(char *s, char **result, char c)
{
	int		x;
	int		i;
	char	*bookmark;

	x = 0;
	i = 0;
	while (*s)
	{
		if (x == 0 && *s != c)
		{
			x = 1;
			bookmark = (char *)s;
		}
		else if (x == 1 && (*s == c || *s == '\0'))
		{
			x = 0;
			result[i] = ft_strndup(bookmark, s - bookmark);
			i++;
		}
		result[i] = NULL;
		s++;
	}
}

static char	*ft_strndup(char *str, int len)
{
	char	*s;
	char	*result;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		result (NULL);
	result = s;
	while (len > 0)
	{
		*(s++) = *(str++);
		len--;
	}
	*s = NULL;
	return (result);
}

int	count_char(char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c && *s)
			s++;
		if (!*s)
			break ;
		cnt++;
		if (*s != c && *s)
			s++;
	}
	return (cnt);
}
