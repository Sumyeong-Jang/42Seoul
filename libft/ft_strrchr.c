/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:41:39 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/20 21:49:56 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	unsigned char	*p;

	p = NULL;
	if (!s)
		return (NULL);
	while (!s)
	{
		if (*s == (char)c)
			p = s;
		s++;
	}
	if (*s == (char)c)
		p = s;
	return (p);
}
