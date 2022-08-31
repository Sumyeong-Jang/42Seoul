/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:18:57 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/31 15:18:58 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int			print_philo_log(t_philo *philo, char *msg);
int			is_finished_lock(t_philo *philo);
void		*ckeck_philos(void *philo);
static int	check_philo_is_died(t_philo *philos, t_arg *arg);
void		print_n_stop_routine(t_philo *philo, t_philo *philos, \
int is_dead, unsigned int eat_times_full);

int	print_philo_log(t_philo *philo, char *msg)
{
	long long	timestamp;

	timestamp = get_ms_time() - philo->arg->start_time;
	if (timestamp == -1)
		return (IS_ERROR);
	pthread_mutex_lock(&(philo->status->is_finished_lock));
	if (!(philo->status->is_finished))
		printf("%lld %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&(philo->status->is_finished_lock));
	return (SUCCESS);
}

int	is_finished_lock(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->status->is_finished_lock);
	ret = philo->status->is_finished;
	pthread_mutex_unlock(&philo->status->is_finished_lock);
	return (ret);
}

void	*ckeck_philos(void *philo)
{
	t_philo	*philos;

	philos = philo;
	while (1)
	{
		if (check_philo_is_died(philos, philos->arg))
			return (NULL);
		usleep(1000);
	}
}

static int	check_philo_is_died(t_philo *philos, t_arg *arg)
{
	unsigned int	i;
	int				is_dead;
	unsigned int	eat_times_full;

	is_dead = 0;
	eat_times_full = 0;
	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_lock(&(philos[i].event_lock));
		if (arg->num_of_eat_times > 0 && \
		(arg->num_of_eat_times < philos[i].eat_count))
			eat_times_full = 1;
		if (arg->time_to_die <= get_ms_time() - philos[i].last_eat_time)
			is_dead = 1;
		pthread_mutex_unlock(&(philos[i].event_lock));
		if (is_dead)
			break ;
		i++;
	}
	print_n_stop_routine(&philos[i], philos, is_dead, eat_times_full);
	return (is_dead || eat_times_full);
}

void	print_n_stop_routine(t_philo *philo, t_philo *philos, \
int is_dead, unsigned int eat_times_full)
{
	if (is_dead)
	{
		print_philo_log(philo, "died");
		stop_routine(philo);
	}
	else if (eat_times_full)
		stop_routine(philos);
}
