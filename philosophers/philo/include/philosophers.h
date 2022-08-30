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
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
//# define TRUE	1
//# define FALSE	0

# define SUCCESS	0
# define IS_ERROR	1

# define ARGC_ERROR			-1
# define FAIL_GET_ARG		-2
# define FAIL_GET_TIME		-3
# define FAIL_MALLOC		-4
# define FAIL_INIT_MUTEX	-5
# define FAIL_INIT_PHILOS	-6
# define FAIL_CREATE_THREAD	-7
# define FAIL_DETACH_THREAD	-8
# define FAIL_DESTROY_MUTEX	-9

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_t		philo_thread; //init philo 에서 사용 안함
	int				idx;
	int				eat_count;
	long long		last_eat_time;

	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*philo_log; //init philo 에서 사용 안함
}					t_philo;

typedef struct s_arg
{
	int		num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_of_eat_times;
	// 변수명 더 직관적으로 변경 가능할듯 (아래 세개)
	int		is_finished;
	int		finished_eat;
	long long	start_time; //입력 안받은거 아닌가
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
}					t_arg;

/*main*/
void		*start_routine(void *argv);
void		check_philo_is_died(t_arg *arg, t_philo *philo);
void		clear_table(t_arg *arg, t_philo *philo);

/*init*/
int			arg_init(int argc, char **argv, t_arg *arg);
int			mutex_init(t_arg *arg);
int			philos_init(t_philo **philo, t_arg *arg);
int			thread_init(t_arg *arg, t_philo *philo);

/*philo_utils*/
int			print_philo_log(t_arg *arg, int idx, char *msg);
void		ms_sleep(long long wait_time, t_arg *arg);
void		*pick_fork_up(t_arg *arg, t_philo *philo);
void		*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork);

/*utils*/
int			ft_error(char *str, int errno);
long long	ft_atoll(char *str);
long long	get_ms_time(void);

#endif