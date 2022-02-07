/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:57:07 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/07 09:42:26 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n);

char	*ft_itoa(int n)
{
	char			*result;
	int				l;
	unsigned int	un_n;

	l = count_len(n);
	result = (char *)malloc(sizeof(char) * (l + 1));
	if (!result)
		return (NULL);
	result[l] = '\0';
	if (n == 0)
		*result = '0';
	else if (n < 0)
	{
		*result = '-';
		n *= -1;
	}
	un_n = n;
	while (un_n > 0)
	{
		result[l - 1] = un_n % 10 + '0';
		un_n /= 10;
		l--;
	}
	return (result);
}

static int	count_len(int n)
{
	int				l;
	unsigned int	un_n;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	un_n = n;
	while (un_n > 9)
	{
		un_n /= 10;
		l++;
	}
	return (l + 1);
}
