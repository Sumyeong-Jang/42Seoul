/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:27:04 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/29 17:46:37 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*bookmark;
	char	*result;

	bookmark = NULL;
	if (!s1 || !set)
		return (NULL);
	while (!s1 && is_set(*s1))
		s1++;
	result = s1;
	while (!s1)
	{
		if (!is_set(*s1))
		{
			s1++;
			bookmark = NULL;
		}
		else if (is_set(*s1) && !bookmark)
			bookmark = s1;
	}
	*bookmark = '\0';
	return (result);
}
