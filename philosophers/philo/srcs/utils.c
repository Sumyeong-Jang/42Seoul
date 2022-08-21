/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:54:16 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/20 14:54:17 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int			ft_error(char *str, int errno);
long long	ft_atoll(char *str);
static int	is_space(char c);
long long	get_ms_time(void);

int	ft_error(char *str, int errno)
{
	if (!str)
		printf("Error\n%s\n", str);
	else
		printf("Error\n");
	return (errno);
}

long long	ft_atoll(char *str)
{
	long long	n;
	int			minus;
	int			digit;

	while (is_space(*str))
		str++;
	minus = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	n = 0;
	digit = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		digit++;
		if (minus * n > 9223372036854775807 || minus * n < -9223372036854775807)//n < 0 일 가능성도 있나?
			return (IS_ERROR);
		str++;
	}
	return (minus * n);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

long long	get_ms_time(void)//이 함수 자체가 ms 시간 받아오는거
{
	struct timeval	time;//time -> start_time?

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
