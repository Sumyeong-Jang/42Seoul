/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:54:42 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/21 17:53:52 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	int				i;

	ch = c;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if ((unsigned char *)s[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
