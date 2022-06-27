/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:50:50 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/10 07:04:23 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
		if (!*s1 || !*s2)
			break ;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
