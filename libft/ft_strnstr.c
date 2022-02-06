/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:30 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/07 05:44:04 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ni;
	size_t	bookmark;

	if (!needle)
		return ((char *)haystack);
	i = 0;
	if (ft_strlen(haystack) < ft_strlen(needle) || \
			len < (size_t)ft_strlen(needle))
		return (NULL);
	while (haystack[i] && i < len)
	{
		ni = 0;
		if (haystack[i] == needle[ni])
		{
			bookmark = i;
			while (haystack[i + ni] == needle[ni] && haystack[i] && needle[ni])
				ni++;
			if (!needle)
				return ((char *)(haystack + bookmark));
		}
		i++;
	}
	return (NULL);
}
