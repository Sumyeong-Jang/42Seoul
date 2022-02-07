/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:14:13 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/07 09:03:33 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_char(char *s, char c);
char	**split(char *str, char c, char **result, int len);

char	*ft_split(char const *s, char c)
{
	int		char_len;
	int		l;
	char	**result;
	char	*str;

	l = 0;
	while (!s[l])
		l++;
	str = (char *)malloc(sizeof(char *) * l + 1);
	l = 0;
	while (!s[l])
	{
		str[l] = s[l];
		l++;
	}
	char_len = count_char(str, c);
	result = (char **)malloc(sizeof(char *) * char_len + 1);
	result = split(str, c, result, char_len);
	return (*result);
}

char	**split(char *str, char c, char **result, int len)
{
	int		x;
	int		y;
	int		i;
	char	*bookmark;

	x = 0;
	while (len--)
	{
		while (*str == c && *str)
			str++;
		y = 0;
		i = 0;
		bookmark = str;
		while (*str != c && *str++)
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
