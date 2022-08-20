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
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int			ft_error(char *str, int errno);
long long	ft_atoll(char *str);
static int	is_space(char c);

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
		if (minus * n > 9223372036854775807 || minus * n < -9223372036854775808)//n < 0 일 가능성도 있나?
			return (RETURN_ERROR);
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

void	mili_sleep(long msec)
{
	long	start;

	start = get_ltime();
	while (get_ltime() < start + msec * 1000)
		usleep(50);
}

void	print_log(t_arg *arg, int philosopher_id, char *message)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(&(arg->log));
	//timestamp_in_ms = get_ltime() - arg->start;
	//if (arg->die == 0)
		printf("%ld %d %s\n", timestamp_in_ms / 1000, \
		philosopher_id, message);
	pthread_mutex_unlock(&(arg->log));
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));//단위가 다름
	//micro_sec = time.tv_sec * 1000000 + time.tv_usec; 디킴꺼
}