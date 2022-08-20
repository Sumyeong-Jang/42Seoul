/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:09:01 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/20 16:09:04 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	arg_init(int argc, char **argv, t_arg *arg);
int	mutex_init(t_arg *arg);
int	philos_init(t_philo **philo, t_arg *arg);

int	arg_init(int argc, char **argv, t_arg *arg)
{
	arg->num_of_philo = ft_atoll(argv[1]);
	arg->time_to_die = ft_atoll(argv[2]);
	arg->time_to_eat = ft_atoll(argv[3]);
	arg->time_to_sleep = ft_atoll(argv[4]);
	// 일단 start time 안받아옴
	if (arg->num_of_philo <= 0 || arg->time_to_die < 0 || \
	arg->time_to_eat < 0 || arg->time_to_sleep < 0)
		return (RETURN_ERROR);
	arg->num_of_eat_times = -1;
	if (argc == 6)
	{
		arg->num_of_eat_times = ft_atoll(argv[5]);
		if (arg->num_of_eat_times < 0)//num_of_eat_times <= 0 ?
			return (RETURN_ERROR);
	}
	return (RETURN_SUCCESS);
}

int	mutex_init(t_arg *arg)
{
	int	i;

	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
	if (!(arg->forks))
		return (RETURN_ERROR);
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL))
			return (RETURN_ERROR);
		i++;
	}
	if (pthread_mutex_init(&(arg->log), NULL))// return값 확인
		return (RETURN_ERROR);
	return (RETURN_SUCCESS);
}

int	philos_init(t_philo **philo, t_arg *arg)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->num_of_philo);
	if (!(philo))
		return (RETURN_ERROR);
	while (i < arg->num_of_philo)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].id = i;
		(*philo)[i].eat_count = 0;
		(*philo)[i].l_fork = arg->forks + i;
		(*philo)[i].r_fork = arg->forks + ((i + 1) % arg->num_of_philo);
		(*philo)[i].last_eat_time = ft_get_time();
		i++;
	}
	return (0);
}

int	init_thread(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->nop)
	{
		if (pthread_create(&(table->philos[i].phil_thread), NULL, \
			start_dining, &(table->philos[i])) != 0)
			return (FALSE);
		i += 2;
		usleep(10);
	}
	i = 1;
	mili_sleep(table->t2e);
	while (i < table->nop && table->die == 0)
	{
		if (pthread_create(&(table->philos[i].phil_thread), NULL, \
			start_dining, &(table->philos[i])) != 0)
			return (FALSE);
		i += 2;
		usleep(10);
	}
	return (TRUE);
}
