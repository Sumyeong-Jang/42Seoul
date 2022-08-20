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

void	clear_table(t_arg *table);

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_philo		*philo;
	//pthread_t	die_check;//t_philo *philo
	// die_check 왜필요함?

	if (argc != 5 && argc != 6)
		return (ft_error("argc error", ARGC_ERROR));
	memset(&arg, 0, sizeof(t_arg));
	if (arg_init(argc, argv, &arg) == RETURN_ERROR)
		return (ft_error("invalid arguments", FAIL_GET_ARG));
	//확인
	if (arg.num_of_eat_times == 0 || arg.num_of_philo == 0)//왜 있지..?
		return (0);
	if (mutex_init(&arg) == RETURN_ERROR)
		return (ft_error("Fail to init mutex", FAIL_INIT_MUTEX));
	if (philo_init(&philo, &arg))
		return (ft_error("Fail to init philos", FAIL_INIT_PHILOS));
	start_philosophers(&arg, philo);





	if (!pthread_create(&die_check, NULL, check_terminate, &arg))
	{
		if (init_thread(&arg) == FALSE)
			return (str_error("Error : Fail to start dining", 1));
		pthread_join(die_check, NULL);
	}
	clear_table(&arg);
	return (0);
}

int	start_philosophers(t_arg *arg, t_philo *philo)
{
	int i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		philo[i].last_eat_time = ft_get_time(); //이게 꼭 필요한가?
		if (pthread_create(&(philo[i].philo_thread), NULL, start_routine, &(philo[i])))
			return (RETURN_ERROR);
	}
}

void	*start_routine(void *argv)
{
	t_arg		*arg;
	t_philo		*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2)
		usleep(1000);
	else
		usleep(500);
	while (!arg->finish)
	{
		ft_philo_action(arg, philo);
		if (arg->num_of_eat_times == philo->eat_count)
		{
			arg->finished_eat++;
			break ;
		}
		ft_philo_printf(arg, philo->id, "is sleeping");
		ft_pass_time((long long)arg->time_to_sleep, arg);
		ft_philo_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

void	clear_table(t_arg *table)
{
	int	i;

	i = -1;
	while (++i < arg->nop)
	{
		if (arg->philos[i].phil_thread != 0)
			pthread_join(arg->philos[i].phil_thread, NULL);
	}
	i = -1;
	while (++i < arg->nop)
		pthread_mutex_destroy(&(arg->forks[i]));
	pthread_mutex_destroy(&(arg->log));
	pthread_mutex_destroy(&(arg->eat));
	pthread_mutex_destroy(&(arg->die_check));
	free(arg->philos);
	free(arg->forks);
}
