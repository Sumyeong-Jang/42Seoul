#include "../include/philosophers.h"

int	print_philo_log(t_philo *philo, char *msg);
void	ms_sleep(long long wait_time, t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);
void	*pick_fork_up(t_arg *arg, t_philo *philo);
void	*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork);

int	print_philo_log(t_philo *philo, char *msg)
{
	long long	timestamp;

	timestamp = get_ms_time() - philo->arg->start_time;
	if (timestamp == -1)
		return (IS_ERROR);
	pthread_mutex_lock(&(philo->status->is_finished_lock));
	if (!(philo->status->is_finished))
		printf("%lld %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&(philo->status->is_finished_lock));
	return (SUCCESS);
}

void	ms_sleep(long long wait_time, t_philo *philo)
{
	long long	start;

	start = get_ms_time();
	while (!(philo->status->is_finished))
	{
		if (get_ms_time() - start >= wait_time)
			break ;
		usleep(10);//usleep(1000)?
	}
}

int	eating(t_philo *philo)
{
	pick_fork_up(philo->arg, philo);
	pthread_mutex_lock(&(philo->status->is_finished_lock));
	philo->last_eat_time = get_ms_time();
	pthread_mutex_unlock(&(philo->status->is_finished_lock));
	print_philo_log(philo, "is eating");
	ms_sleep(philo->arg->time_to_eat, philo);
	pthread_mutex_lock(&(philo->status->is_finished_lock));
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->status->is_finished_lock));
	put_fork_down(philo->lfork, philo->rfork);
	//return (is_end_simulation(philo));//
	return (philo->status->is_finished);
}

int	sleeping(t_philo *philo)//main으로 옮기고 static
{
	print_philo_log(philo, "is sleeping");
	ms_sleep(philo->arg->time_to_sleep, philo);
	//return (is_end_simulation(philo));
	return (philo->status->is_finished);
}

int	thinking(t_philo *philo)
{
	print_philo_log(philo, "is thinking");
	usleep(1000);
	//return (is_end_simulation(philo));
	return (philo->status->is_finished);
}

void	*pick_fork_up(t_arg *arg, t_philo *philo)//함수 인자 개수를 적게 쓰는게 좋지 않을까?
{
	pthread_mutex_lock(philo->lfork);
	//if (philo->status->is_finished == 1)
	//	return (put_fork_down(philo->lfork, NULL));
	print_philo_log(philo, "has taken a fork");
	//if (philo->rfork == philo->lfork)
	//	return (put_fork_down(philo->lfork, NULL));
	pthread_mutex_lock(philo->rfork);
	//if (philo->status->is_finished == 1)
	//	return (put_fork_down(philo->lfork, philo->rfork));
	print_philo_log(philo, "has taken a fork");
	//philo->last_eat_time = get_ms_time();
	//return ((void *)philo);
}

void	*put_fork_down(pthread_mutex_t *lfork, pthread_mutex_t *rfork)
{
	if (lfork != NULL)
		pthread_mutex_unlock(lfork);
	if (rfork != NULL)
		pthread_mutex_unlock(rfork);
	return (NULL);
}
