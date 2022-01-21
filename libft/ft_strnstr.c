/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:10:30 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/21 18:24:23 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ni;
	size_t	bookmark;

	i = 0;
	if (!needle)
		return (haystack);
	while (haystack[i] && i < len)
	{
		ni = 0;
		if (haystack[i] == needle[ni])
		{
			bookmark = i;
			while (haystack[i + ni] == needle[ni] && haystack[i] && needle[ni])
				ni++;
			if (!needle)
				return (&haystack[bookmark]);
		}
		i++;
	}
	return (NULL);
}
