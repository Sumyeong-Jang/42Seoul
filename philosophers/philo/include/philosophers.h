/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:54:24 by sumjang           #+#    #+#             */
/*   Updated: 2022/08/20 14:54:25 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
//# define TRUE	1
//# define FALSE	0

# define SUCCESS	0
# define IS_ERROR	1

# define ARGC_ERROR			-1
# define FAIL_GET_ARG		-2
# define FAIL_GET_TIME		-3
# define FAIL_MALLOC		-4
# define FAIL_INIT_PHILOS	-5
# define FAIL_INIT_MUTEX	-6
# define FAIL_CREATE_THREAD	-7
# define FAIL_DETACH_THREAD	-8
# define FAIL_DESTROY_MUTEX	-9

typedef struct s_philo
{
	struct s_arg	*arg;
	struct s_status	*status;
	pthread_t		philo_thread; //init philo 에서 사용 안함
	int				id;
	int				eat_count;
	long long		last_eat_time;
	pthread_mutex_t	event_lock;
	pthread_mutex_t	is_finished_lock;
	int				is_finished;
	pthread_mutex_t	fork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
}					t_philo;

typedef struct s_arg
{
	int		num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_of_eat_times;
	int		finished_eat;
	long long	start_time;
}					t_arg;

typedef struct s_status
{
	pthread_mutex_t	is_finished_lock;
	int				is_finished;
}					t_status;

/*main*/
void	*start_routine(void *argv);
void	*one_philo_routine(t_philo *philo);
void	*ckeck_philos(void *philo);
void	check_philo_is_died(t_arg *arg, t_philo *philos)
void	destroy_mutex(t_arg *arg, t_philo *philos);

/*init*/
int		arg_init(int argc, char **argv, t_arg *arg);
int		philos_init(t_philo **philos, t_arg *arg, t_status *status);
int		mutex_init(t_philo *philos, t_arg *arg, t_status *status);
static int	ft_mutex_init(t_philo *philo);
int		thread_init(t_arg *arg, t_philo *philo);
void	stop_routine(t_philo *philo);

/*philo_utils*/
int			print_philo_log(t_arg *arg, int idx, char *msg);
void		ms_sleep(long long wait_time, t_arg *arg);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
int			thinking(t_philo *philo);
void		*pick_fork_up(t_arg *arg, t_philo *philo);
void		*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork);

/*utils*/
int			ft_error(char *str, int errno);
long long	ft_atoll(char *str);
long long	get_ms_time(void);

#endif
