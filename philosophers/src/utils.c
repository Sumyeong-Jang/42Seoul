#include "../include/philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

long	get_ltime(void)
{
	struct timeval	time;
	long			micro_sec;

	gettimeofday(&time, NULL);
	micro_sec = time.tv_sec * 1000000 + time.tv_usec;
	return (micro_sec);
}

int	str_error(char *str, int ret)
{
	if (str != NULL)
		printf("%s\n", str);
	return (ret);
}

long	ft_atou(char *str)
{
	long	num;

	if (str == NULL)
		return (-1);
	num = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	while (TRUE)
	{
		if (*str >= '0' && *str <= '9' && num >= 0)
			num = num * 10 + *str - '0';
		else
			break ;
		str++;
		if (*str == 0)
			return (num);
	}
	return (-1);
}

void	mili_sleep(long msec)
{
	long	start;
	
	start = get_ltime();
	while (get_ltime() < start + msec * 1000)
		usleep(50);
}

void	print_log(t_table *table, int philosopher_id, char *message)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(&(table->log));
	timestamp_in_ms = get_ltime() - table->start;
	if (table->die == 0)
		printf("%ld %d %s\n", timestamp_in_ms / 1000, \
		philosopher_id, message);
	pthread_mutex_unlock(&(table->log));
}