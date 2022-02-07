/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:57:29 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/07 22:07:46 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*result;
	unsigned int	sl;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (sl <= start || len == 0)
		return (ft_strdup(""));
	if (len >= sl)
		len = sl;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	result = str;
	while (len > 0)
	{
		*(str++) = s[start++];
		len--;
	}
	*str = '\0';
	return (result);
}
