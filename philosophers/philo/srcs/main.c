/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:53:57 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/31 13:16:39 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void		*start_routine(void *argv);
static void	*one_philo_routine(t_philo *philo);
static void	destroy_mutex(t_arg *arg, t_philo *philos);

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_status	status;
	t_philo		*philos;

	memset(&arg, 0, sizeof(t_arg));
	if (arg_init(argc, argv, &arg) == IS_ERROR)
		return (ft_error("invalid arguments", FAIL_GET_ARG));
	if (philos_init(&philos, &arg, &status))
		return (ft_error("Fail to init philos", FAIL_INIT_PHILOS));
	if (mutex_init(philos, &arg, &status) == IS_ERROR)
	{
		free(philos);
		return (ft_error("Fail to init mutex", FAIL_INIT_MUTEX));
	}
	if (thread_init(philos, &arg) == IS_ERROR)
	{
		destroy_mutex(&arg, philos);
		free(philos);
		return (ft_error("Fail to create thread", FAIL_CREATE_THREAD));
	}
	destroy_mutex(&arg, philos);
	free(philos);
	return (SUCCESS);
}

void	*start_routine(void *argv)
{
	t_philo	*philos;

	philos = (t_philo *)argv;
	if (philos->arg->num_of_philo == 1)
		return (one_philo_routine(philos));
	if (philos->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (eating(philos))
			return (NULL);
		if (sleeping(philos))
			return (NULL);
		if (thinking(philos))
			return (NULL);
	}
	return (NULL);
}

static void	*one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_philo_log(philo, "has taken a fork\n");
	while (!is_finished_lock(philo))
		usleep(1000);
	pthread_mutex_unlock(philo->lfork);
	return (NULL);
}

static void	destroy_mutex(t_arg *arg, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(&(philos->status->is_finished_lock));
	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_destroy(&(philos[i].fork));
		pthread_mutex_destroy(&(philos[i].event_lock));
		i++;
	}
}
