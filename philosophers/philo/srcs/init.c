/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:09:01 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/31 13:16:11 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int			arg_init(int argc, char **argv, t_arg *arg);
int			philos_init(t_philo **philos, t_arg *arg, t_status *status);
int			mutex_init(t_philo *philos, t_arg *arg, t_status *status);
static int	ft_mutex_init(t_philo *philo);

int	arg_init(int argc, char **argv, t_arg *arg)
{
	if (argc != 5 && argc != 6)
		return (IS_ERROR);
	arg->num_of_philo = ft_atoll(argv[1]);
	arg->time_to_die = ft_atoll(argv[2]);
	arg->time_to_eat = ft_atoll(argv[3]);
	arg->time_to_sleep = ft_atoll(argv[4]);
	if (arg->num_of_philo <= 0 || arg->time_to_die < 0 || \
	arg->time_to_eat < 0 || arg->time_to_sleep < 0)
		return (IS_ERROR);
	arg->num_of_eat_times = -1;
	if (argc == 6)
	{
		arg->num_of_eat_times = ft_atoll(argv[5]);
		if (arg->num_of_eat_times <= 0)
			return (IS_ERROR);
	}
	return (SUCCESS);
}

int	philos_init(t_philo **philos, t_arg *arg, t_status *status)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * arg->num_of_philo);
	if (!(philos))
		return (IS_ERROR);
	status->is_finished = 0;
	i = 0;
	while (i < arg->num_of_philo)
	{
		(*philos)[i].arg = arg;
		(*philos)[i].status = status;
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_count = 0;
		(*philos)[i].lfork = &((*philos)[i].fork);
		(*philos)[i].rfork = &((*philos)[(i + 1) % arg->num_of_philo].fork);
		i++;
	}
	return (SUCCESS);
}

int	mutex_init(t_philo *philos, t_arg *arg, t_status *status)
{
	int	i;

	if (pthread_mutex_init(&(status->is_finished_lock), NULL) != SUCCESS)
		return (IS_ERROR);
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (ft_mutex_init(&(philos[i])) != SUCCESS)
		{
			while (i--)
			{
				pthread_mutex_destroy(&(philos[i].fork));
				pthread_mutex_destroy(&(philos[i].event_lock));
			}
			pthread_mutex_destroy(&(status->is_finished_lock));
			return (IS_ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

static int	ft_mutex_init(t_philo *philo)
{
	if (pthread_mutex_init(&(philo->fork), NULL))
		return (IS_ERROR);
	if (pthread_mutex_init(&(philo->event_lock), NULL))
	{
		pthread_mutex_destroy(&(philo->fork));
		return (IS_ERROR);
	}
	return (SUCCESS);
}
