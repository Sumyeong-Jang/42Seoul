/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:53:57 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/20 14:53:59 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*start_routine(void *argv);
void	*one_philo_routine(t_philo *philo);
void	check_philo_is_died(t_arg *arg, t_philo *philo);
void	clear_table(t_arg *arg, t_philo *philo);

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		return (ft_error("argc error", ARGC_ERROR));
	memset(&arg, 0, sizeof(t_arg));
	if (arg_init(argc, argv, &arg) == IS_ERROR)
		return (ft_error("invalid arguments", FAIL_GET_ARG));
	if (mutex_init(&arg) == IS_ERROR)
		return (ft_error("Fail to init mutex", FAIL_INIT_MUTEX));
	if (philos_init(&philo, &arg))
	{
		free(philo);
		destroy_mutex(&arg);
		return (ft_error("Fail to init philos", FAIL_INIT_PHILOS));
	}
	if (thread_init(&arg, philo) == IS_ERROR)
	{
		free(philo);
		destroy_mutex(&arg);
		return (ft_error("Fail to create thread", FAIL_CREATE_THREAD));
	}
	clear_table(&arg, philo);
	return (0);
}

void	*start_routine(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = argv;
	arg = philo->arg;
	if (arg->num_of_philo == 1)
		return (one_philo_routine(philo));
	//디킴 print_philo_log(arg, idx, "is eating");
	//usleep 조건ㄱ : idx % 2 == 0 일때 usleep(1000) ?
	if (philo->idx % 2)//디킴 sleep(arg->time_to_eat)
		usleep(1000);
	else
		usleep(500);//usleep(200 * (철학자수 - idx))  --> 이거 왜......?
	while (1)
	{
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
	/*
	while (!arg->is_finished)
	{
		if (pick_fork_up(arg, philo) == NULL)
			return (NULL);
		print_philo_log(arg, philo->idx, "is eating");
		ms_sleep(arg->time_to_eat, arg);
		if (arg->is_finished == 1)
			return (put_fork_down(philo->lfork, philo->rfork));
		philo->eat_count++;
		//pthread_mutex_lock(&(arg->eat));?

		if (arg->num_of_eat_times > 0 && (philo->eat_count == arg->num_of_eat_times))
			arg->finished_eat++;
			// break ?
		//pthread_mutex_unlock(&(arg->eat));eat vs t2e
		print_philo_log(arg, philo->idx, "is sleeping");
		put_fork_down(philo->lfork, philo->rfork);
		ms_sleep(arg->time_to_sleep, arg);
		print_philo_log(arg, philo->idx, "is thinking");
	}
	*/
	return (NULL);
}

void	*one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_philo_log(philo->arg, philo->idx, "has taken a fork\n");
	//while (!is_end_simulation(philo))//
	while (!(philo->arg->is_finished))
		usleep(1000);//usleep(TIME_FOR_CONTEXT_SWITCHING);//usleep(1000)
	pthread_mutex_unlock(philo->lfork);
	return (NULL);
}

void	check_philo_is_died(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	while (!arg->is_finished)
	{
		if ((arg->num_of_eat_times != 0) && \
		(arg->num_of_philo == arg->finished_eat))
		{
			arg->is_finished = 1;
			break ;
		}
		i = 0;
		while (i < arg->num_of_philo)
		{
			now = get_ms_time();
			if ((now - philo[i].last_eat_time) >= arg->time_to_die)
			{
				print_philo_log(arg, i, "died");
				arg->is_finished = 1;//stop simulation 쓰는 이유?
				break ;
			}
			i++;
		}
	}
}

void	clear_table(t_arg *arg, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < arg->num_of_philo)
	{
		if (philo[i].philo_thread != 0)
			pthread_join(philo[i].philo_thread, NULL);
	}
	i = -1;
	while (++i < arg->num_of_philo)
		pthread_mutex_destroy(&(arg->forks[i]));
	pthread_mutex_destroy(&(arg->log));
	//pthread_mutex_destroy(&(arg->eat));
	//pthread_mutex_destroy(&(arg->die_check));
	free(philo);
	free(arg->forks);
}
