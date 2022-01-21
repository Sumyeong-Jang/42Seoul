/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:55 by sumjang           #+#    #+#             */
/*   Updated: 2022/01/21 20:03:48 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char ch);

int	ft_atoi(const char *str)
{
	int	n;
	int	minus;

	n = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		minus = -1;
	str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (minus * n);
}

int	is_space(char ch)
{
	if (ch >= 8 && ch <= 13)
		return (1);
	if (ch == 32)
		return (1);
	return (0);
}
