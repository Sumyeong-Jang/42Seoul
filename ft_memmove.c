/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:22:48 by sumjang           #+#    #+#             */
/*   Updated: 2021/11/22 16:51:45 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	source = src;
	if (dest < source)
	{
		i = -1;
		while (++i < len)
			dest[i] = source[i];
	}
	else
	{
		i = len + 1;
		while (--i)
			dest[i - 1] = source[i - 1];
	}
	return (dest);
}
