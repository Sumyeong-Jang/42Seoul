#include "../include/philosophers.h"

int		print_philo_log(t_arg *arg, int idx, char *msg);
void	ms_sleep(long long wait_time, t_arg *arg);
void	*pick_fork_up(t_arg *arg, t_philo *philo);
void	*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork);

int	print_philo_log(t_arg *arg, int idx, char *msg)
{
	long long	timestamp;

	timestamp = get_ms_time() - arg->start_time;
	if (timestamp == -1)
		return (-1);
	pthread_mutex_lock(&(arg->log));
	if (!(arg->is_finished))
		printf("%lld %d %s\n", timestamp, idx + 1, msg);
	pthread_mutex_unlock(&(arg->log));
	return (0);
}

void	ms_sleep(long long wait_time, t_arg *arg)
{
	long long	start;

	start = get_ms_time();
	while (!(arg->is_finished))
	{
		if (get_ms_time() - start >= wait_time)
			break ;
		usleep(10);
	}
}

void	*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork)
{
	if (lfork != NULL)
		pthread_mutex_unlock(lfork);
	if (rfork != NULL)
		pthread_mutex_unlock(rfork);
	return (NULL);
}

void	*pick_fork_up(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	if (arg->is_finished == 1)
		return (put_fork_down(philo->rfork, NULL));
	print_philo_log(arg, philo->idx, "has taken a fork");
	if (philo->rfork == philo->lfork)
		return (put_fork_down(philo->rfork, NULL));
	pthread_mutex_lock(philo->lfork);
	if (arg->is_finished == 1)
		return (put_fork_down(philo->rfork, philo->lfork));
	print_philo_log(arg, philo->idx, "has taken a fork");
	philo->last_eat_time = get_ms_time();
	return ((void *)philo);
}

