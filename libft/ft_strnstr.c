/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:30 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/06 15:13:44 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ni;
	size_t	bookmark;

	if (!haystack)
		return (NULL);
	if (!needle)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		ni = 0;
		if (haystack[i] == needle[ni])
		{
			bookmark = i;
			while (haystack[i + ni] == needle[ni] && haystack[i] && needle[ni])
				ni++;
			if (!needle)
				return ((char)haystack[bookmark]);
		}
		i++;
	}
	return (NULL);
}
