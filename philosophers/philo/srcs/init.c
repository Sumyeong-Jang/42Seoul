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
void	destroy_mutex(t_arg *arg);
int		philos_init(t_philo **philo, t_arg *arg);
int		thread_init(t_arg *arg, t_philo *philo);
void	stop_routine(t_philo *philo);

int	arg_init(int argc, char **argv, t_arg *arg) // 왜 long long 인지?
{
	arg->num_of_philo = ft_atoll(argv[1]);
	arg->time_to_die = ft_atoll(argv[2]);
	arg->time_to_eat = ft_atoll(argv[3]);
	arg->time_to_sleep = ft_atoll(argv[4]);
	// 일단 start time 안받아옴
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

int	mutex_init(t_arg *arg)
{
	int	i;

	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
	if (!(arg->forks))
		return (IS_ERROR);
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL) != SUCCESS)
		{
			while (i--)
				pthread_mutex_destroy(&(arg->forks[i]));
			return (IS_ERROR);
		}
		i++;
	}
	if (pthread_mutex_init(&(arg->log), NULL) != SUCCESS)
	{
		while (i--)
			pthread_mutex_destroy(&(arg->forks[i]));
		pthread_mutex_destroy(&(arg->log));
		return (IS_ERROR);
	}
	return (SUCCESS);
}

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

int	philos_init(t_philo **philo, t_arg *arg)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->num_of_philo);
	if (!(philo))
		return (IS_ERROR);
	while (i < arg->num_of_philo)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].idx = i;
		(*philo)[i].eat_count = 0;
		(*philo)[i].lfork = arg->forks + i;
		(*philo)[i].rfork = arg->forks + ((i + 1) % arg->num_of_philo);
		(*philo)[i].last_eat_time = get_ms_time();
		i++;
	}
	return (0);
}

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
			stop_routine(&philo[i]);
			//join_philos 함수
			while (i--)
				pthread_join(philos[i].philo_thread, NULL);
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

void	stop_routine(t_philo *philo) //end state 정리
{
	pthread_mutex_lock(&philo->end_state->is_end_lock);
	philo->end_state->is_end = 1;
	pthread_mutex_unlock(&philo->end_state->is_end_lock);
}