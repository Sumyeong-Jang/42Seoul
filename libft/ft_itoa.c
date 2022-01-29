/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:57:07 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/29 18:29:38 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_minus(int n);

char	*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*result;

	if (n < 0)
		ft_itoa_minus(n * -1);
	i = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	if (n != 0)
		i--;
	result = (char *)malloc(i * sizeof(char) + 1);
	while (i >= 0)
	{
		result[i + tmp] = n % 10;
		n /= 10;
		i--;
	}
	return (result);
}

char	*ft_itoa_minus(int n)
{
	int		i;
	int		tmp;
	char	*result;

	i = 1;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	result = (char *)malloc(i * sizeof(char) + 1);
	while (i > 0)
	{
		result[i + tmp] = n % 10;
		n /= 10;
		i--;
	}
	result[i] = '-';
	return (result);
}
