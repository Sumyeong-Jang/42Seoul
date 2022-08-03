/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:55 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/10 09:18:07 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char ch);

int	ft_atoi(const char *str)
{
	long	cnt;
	int		minus;
	size_t	n;

	while (is_space(*str))
		str++;
	minus = 1;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	cnt = LONG_MAX;
	while (*str >= '0' && *str <= '9')
	{
		if (minus == -1 && (!cnt || n > -(size_t)LONG_MIN))
			return ((int)LONG_MIN);
		if (minus == 1 && (!cnt || n > (size_t)LONG_MAX))
			return ((int)LONG_MAX);
		n = (n * 10) + (*str - '0');
		cnt = cnt / 10;
		str++;
	}
	return (minus * n);
}

static int	is_space(char ch)
{
	if (ch >= 8 && ch <= 13)
		return (1);
	if (ch == 32)
		return (1);
	return (0);
}
