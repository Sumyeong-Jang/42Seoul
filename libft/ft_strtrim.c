/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:27:04 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/10 08:03:58 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set);
static char	*ft_strndup(char const *s, int start, int len);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (!is_set(s1[i], set))
			break ;
		i++;
	}
	if (i == len)
		return (ft_strndup(s1, 0, 0));
	while (len > 0)
	{
		if (!is_set(s1[len - 1], set))
			break ;
		len--;
	}
	str = ft_strndup(s1, i, len - i);
	return (str);
}

static char	*ft_strndup(char const *s, int start, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
