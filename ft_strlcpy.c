/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:43:03 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/24 04:30:29 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	src_len;

	idx = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (src[idx] != '\0' && dstsize > 1)
	{
		dest[idx] = src[idx];
		idx++;
		dstsize--;
	}
	dest[idx] = '\0';
	return (src_len);
}
