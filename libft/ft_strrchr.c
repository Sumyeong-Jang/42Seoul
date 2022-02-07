/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:41:39 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/07 09:30:37 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*p;

	p = NULL;
	while (1)
	{
		if (*s == (unsigned char)c)
			p = (char *)s;
		if (!*s)
			break ;
		s++;
	}
	return (p);
}
