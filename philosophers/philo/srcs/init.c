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

int		arg_init(int argc, char **argv, t_arg *arg);
int		mutex_init(t_arg *arg);
int		philos_init(t_philo **philo, t_arg *arg, t_status *status);
void	destroy_mutex(t_arg *arg);
int		thread_init(t_arg *arg, t_philo *philo);
//void	stop_routine(t_philo *philo);

int	arg_init(int argc, char **argv, t_arg *arg) // 왜 long long 인지?
{
	arg->num_of_philo = ft_atoll(argv[1]);
	arg->time_to_die = ft_atoll(argv[2]);
	arg->time_to_eat = ft_atoll(argv[3]);
	arg->time_to_sleep = ft_atoll(argv[4]);
	//arg->start_time = get_ms_time();
	if (arg->num_of_philo <= 0 || arg->time_to_die < 0 || \
	arg->time_to_eat < 0 || arg->time_to_sleep < 0)
		return (IS_ERROR);
	//arg->num_of_eat_times = -1;//디폴트가 -1인게 맞나?
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

	i = 0;
	status->is_finished = 0;
	*philos = malloc(sizeof(t_philo) * arg->num_of_philo);
	if (!(philos))
		return (IS_ERROR);
	while (i < arg->num_of_philo)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].status = status;
		(*philo)[i].idx = i + 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].lfork = &((*philos)[i].fork);
		(*philo)[i].rfork = &(philos[(i + 1) % arg->num_of_philo].fork);
		i++;
	}
	is_finished = 0;
	return (0);
}

int	mutex_init(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(status->is_finished_lock), NULL) != SUCCESS)
		return (IS_ERROR);
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (ft_mutex_init(&(arg->forks[i]), NULL) != SUCCESS)
		{
			while (i--)
			{
				pthread_mutex_destroy(&(philos[i].fork));
				pthread_mutex_destroy(&(philos[i].event_lock));
			}
			free(arg->forks);
			return (IS_ERROR);
		}
		i++;
	}
	if (pthread_mutex_init(&(arg->log), NULL) != SUCCESS)
	{
		while (i--)
			pthread_mutex_destroy(&(arg->forks[i]));
		pthread_mutex_destroy(&(arg->log));
		free(arg->forks);
		return (IS_ERROR);
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
	return (0);
}

/*
void	destroy_mutex(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_destroy(&(arg->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(arg->log));
}
*/

int	thread_init(t_arg *arg, t_philo *philo)
{
	int			i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		philo[i].last_eat_time = get_ms_time();//꼭 필요한가?
		if (pthread_create(&(philo[i].philo_thread), NULL, \
		start_routine, &(philo[i])) != SUCCESS)
		{
			arg->is_finished=1;//stop_routine(&philo[i]);
			//join_philos 함수
			while (i--)
				pthread_join(philo[i].philo_thread, NULL);
			return (IS_ERROR); //stop simulation 추가
		}
		usleep(200);//꼭 필요한가?
		i++;
	}
	check_philo_is_died(arg, philo);
	i = 0;
	while (i < arg->num_of_philo)
	{
		// 메인 쓰레드의 대기 영역 //
		pthread_join(philo[i].philo_thread, NULL);
		i++;
	}
	return (SUCCESS);
}

/*
void	stop_routine(t_philo *philo) //end state 정리
{
	pthread_mutex_lock(&philo->end_state->is_end_lock);
	philo->end_state->is_end = 1;
	pthread_mutex_unlock(&philo->end_state->is_end_lock);
}
*/
