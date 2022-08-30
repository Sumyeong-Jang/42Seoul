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
void	*ckeck_philos(void *philo);
int		check_philo_is_died(t_philo *philos, t_arg *arg);
void	destroy_mutex(t_arg *arg, t_philo *philos);

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_status	status;
	t_philo		*philos;

	if (argc != 5 && argc != 6)
		return (ft_error("argc error", ARGC_ERROR));
	memset(&arg, 0, sizeof(t_arg));
	if (arg_init(argc, argv, &arg) == IS_ERROR)
		return (ft_error("invalid arguments", FAIL_GET_ARG));
	if (philos_init(&philos, &arg, &status))
	{
		free(philos);
		return (ft_error("Fail to init philos", FAIL_INIT_PHILOS));
	}
	if (mutex_init(philos, &arg, &status) == IS_ERROR)
	{
		free(philos);
		destroy_mutex(&arg, philos);
		return (ft_error("Fail to init mutex", FAIL_INIT_MUTEX));
	}
	if (thread_init(philos, &arg) == IS_ERROR)
	{
		free(philos);
		destroy_mutex(&arg, philos);
		return (ft_error("Fail to create thread", FAIL_CREATE_THREAD));
	}
	free(philos);//순서?
	destroy_mutex(&arg, philos);
	return (SUCCESS);
}

void	*start_routine(void *argv)
{
	//t_arg	*arg;
	t_philo	*philos;

	philos = (t_philo *)argv;
	if (philos->arg->num_of_philo == 1)
		return (one_philo_routine(philos));
	//usleep 조건ㄱ : idx % 2 == 0 일때 usleep(1000) ?
	/*
	if (philos->id % 2)//디킴 sleep(arg->time_to_eat)
		usleep(1000);
	else
		usleep(500);//usleep(200 * (철학자수 - idx))  --> 이거 왜......?
	*/
	if (philos->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (eating(philos))
			return (NULL);
		if (philos->arg->num_of_eat_times == philos->eat_count)
		{
			philos->arg->finished_eat++;
			break ;
		}
		if (sleeping(philos))
			return (NULL);
		if (thinking(philos))
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
	print_philo_log(philo, "has taken a fork\n");
	//while (!is_end_simulation(philo))//
	while (!(philo->is_finished))
		usleep(1000);//usleep(TIME_FOR_CONTEXT_SWITCHING);//usleep(1000)
	pthread_mutex_unlock(philo->lfork);
	return (NULL);
}

void	*ckeck_philos(void *philo)
{
	t_philo	*philos;

	philos = philo;
	while (1)
	{
		if (check_philo_is_died(philos, philos->arg))
			return (NULL);
		usleep(1000);//usleep(TIME_FOR_CONTEXT_SWITCHING);
	}
}

int	check_philo_is_died(t_philo *philos, t_arg *arg)//static int 
{
	int			i;
	long long	now;

	while (!(philos->is_finished))
	{
		if ((arg->num_of_eat_times != 0) && \
		(arg->num_of_philo == arg->finished_eat))// finished_eat == 1 일때 아닌가 :: everyone is full
		{
			philos->is_finished = 1;
			//stop_routine
			break;
		}
		i = 0;
		while (i < arg->num_of_philo)
		{
			//event_lock 이 필요함? -> youjeon에서의 print?
			now = get_ms_time();
			if ((now - philos[i].last_eat_time) >= arg->time_to_die)
			{
				print_philo_log(&philos[i], "died");
				// is_finished = 1 하기 앞 뒤로 pthread_mutex_lock(status->is_finished_lock) 해줘야하나ㅏ?
				philos->is_finished = 1;
				//stop_routine
				break ;
			}
			i++;
		}
		return (philos->is_finished);
	}
	return (philos->is_finished);
}

void	destroy_mutex(t_arg *arg, t_philo *philos)
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
	//free(philos_init);//
	//free(arg->forks);//
}
