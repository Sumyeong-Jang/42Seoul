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

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//# define TRUE	1
//# define FALSE	0

# define RETURN_ERROR	1
# define RETURN_SUCCESS	0

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
	pthread_t		philo_thread;//init philo 에서 사용 안함
	int				id;
	int				eat_count;
	long long		last_eat_time;

	// pthread_mutex_t 인걸 int 로 구현 가능?
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*philo_log;//init philo 에서 사용 안함
}					t_philo;

typedef struct s_arg
{
	int		num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_of_eat_times;
	// 변수명 더 직관적으로 변경 가능할듯
	int		finish;
	int		finished_eat;
	long long	start_time;//입력 안받은거 아닌가
	// 이렇게 세개
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
}					t_arg;

/*
	int			die; -> finish
	int			full;-> finished_eat
	long		start;->start_time
}				t_arg;
*/

/*utils*/
int			ft_error(char *str, int errno);
long long	ft_atoll(char *str);
static int	is_space(char c);

/*init*/
int	arg_init(int argc, char **argv, t_arg *arg);
int	mutex_init(t_arg *arg);
int	philos_init(t_philo **philo, t_arg *arg);

#endif
