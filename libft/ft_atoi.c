/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:55 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/08 20:19:24 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char ch);

int	ft_atoi(const char *str)
{
	long	n;
	long	minus;

	n = 0;
	minus = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		if (n > 2147483647 && minus == 1)
			return (-1);
		if (n > 2147483648 && minus == -1)
			return (0);
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
