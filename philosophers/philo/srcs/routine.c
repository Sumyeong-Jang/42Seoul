/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:16:29 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/31 15:16:30 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int			thread_init(t_philo *philo, t_arg *arg);
void		stop_routine(t_philo *philo);
static int	ft_join(t_philo *philos, int i);
static int	ft_join_all(pthread_t *check, t_philo *philos, int i);

int	thread_init(t_philo *philos, t_arg *arg)
{
	int			i;
	pthread_t	check;

	philos->arg->start_time = get_ms_time();
	i = 0;
	while (i < arg->num_of_philo)
	{
		philos[i].last_eat_time = arg->start_time;
		if (pthread_create(&(philos[i].philo_thread), NULL, \
		start_routine, &(philos[i])) != SUCCESS)
		{
			stop_routine(&philos[i]);
			return (ft_join(philos, i));
		}
		i++;
	}
	if (pthread_create(&check, NULL, ckeck_philos, philos) != SUCCESS)
	{
		stop_routine(&philos[i]);
		return (ft_join_all(&check, philos, i));
	}
	ft_join_all(&check, philos, i);
	return (SUCCESS);
}

void	stop_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->status->is_finished_lock);
	philo->status->is_finished = 1;
	pthread_mutex_unlock(&philo->status->is_finished_lock);
}

static int	ft_join(t_philo *philos, int i)
{
	while (i--)
		pthread_join(philos[i].philo_thread, NULL);
	return (IS_ERROR);
}

static int	ft_join_all(pthread_t *check, t_philo *philos, int i)
{
	ft_join(philos, i);
	pthread_join(*check, NULL);
	return (IS_ERROR);
}
