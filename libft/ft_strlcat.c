/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:46:37 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/24 04:35:05 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	idx = 0;
	while (*src != '\0' && idx + 1 < dstsize)
	{
		dest[idx] = *src;
		src++;
		idx++;
	}
	dest[idx] = '\0';
	if (dstsize <= dest_len)
		return (src_len + dstsize);
	else
		return (src_len + dest_len);
}
