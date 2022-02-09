/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:30 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/10 07:05:04 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + nlen <= len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j])
			{
				if (haystack[i + j] != needle[j])
					break ;
				else if (j == nlen - 1)
					return ((char *)haystack + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
