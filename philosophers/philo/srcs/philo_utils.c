/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:14:04 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/31 13:16:45 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
int			thinking(t_philo *philo);
static void	*pick_fork_up(t_philo *philo);
static void	*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork);

int	eating(t_philo *philo)
{
	pick_fork_up(philo);
	pthread_mutex_lock(&(philo->event_lock));
	philo->last_eat_time = get_ms_time();
	pthread_mutex_unlock(&(philo->event_lock));
	print_philo_log(philo, "is eating");
	ms_sleep(philo->arg->time_to_eat, philo);
	pthread_mutex_lock(&(philo->event_lock));
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->event_lock));
	put_fork_down(philo->lfork, philo->rfork);
	return (is_finished_lock(philo));
}

int	sleeping(t_philo *philo)
{
	print_philo_log(philo, "is sleeping");
	ms_sleep(philo->arg->time_to_sleep, philo);
	return (is_finished_lock(philo));
}

int	thinking(t_philo *philo)
{
	print_philo_log(philo, "is thinking");
	usleep(1000);
	return (is_finished_lock(philo));
}

static void	*pick_fork_up(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_philo_log(philo, "has taken a fork");
	pthread_mutex_lock(philo->rfork);
	print_philo_log(philo, "has taken a fork");
	return ((void *)philo);
}

static void	*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork)
{
	if (lfork != NULL)
		pthread_mutex_unlock(lfork);
	if (rfork != NULL)
		pthread_mutex_unlock(rfork);
	return (NULL);
}
