#include "../include/philosophers.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	*start_dining(void *vargp)
{
	t_philo	*philo;

	philo = vargp;
	while (philo->tab->die == 0)
	{
		if (pick_fork_up(philo) == NULL)
			return (NULL);
		print_log(philo->tab, philo->id, "is eating");
		mili_sleep(philo->tab->t2e);
		if (philo->tab->die == 1)
			return (put_fork_down(philo->lfork, philo->rfork));
		philo->eat_count++;
		pthread_mutex_lock(&(philo->tab->eat));
		if (philo->tab->noe > 0 && (philo->eat_count == philo->tab->noe))
			philo->tab->full++;
		pthread_mutex_unlock(&(philo->tab->eat));
		print_log(philo->tab, philo->id, "is sleeping");
		put_fork_down(philo->lfork, philo->rfork);
		mili_sleep(philo->tab->t2s);
		print_log(philo->tab, philo->id, "is thinking");
	}
	return (NULL);
}

void	*check_terminate(void *vargp)
{
	t_table	*table;
	int		i;

	table = vargp;
	while (table->die == 0)
	{
		pthread_mutex_lock(&(table->die_check));
		if (table->full >= table->nop)
			table->die = 1;
		pthread_mutex_unlock(&(table->die_check));
		i = -1;
		while (++i < table->nop && table->die == 0)
		{
			usleep(10);
			pthread_mutex_lock(&(table->die_check));
			if (table->philos[i].last_eat + table->t2d * 1000 <= get_ltime())
			{
				print_log(table, table->philos[i].id, "died");
				table->die = 1;
			}
			pthread_mutex_unlock(&(table->die_check));
		}
		usleep(10);
	}
	return (NULL);
}

void	*put_fork_down(t_mutex *lfork, t_mutex *rfork)
{
	if (lfork != NULL)
		pthread_mutex_unlock(lfork);
	if (rfork != NULL)
		pthread_mutex_unlock(rfork);
	return (NULL);
}

void	*pick_fork_up(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	if (philo->tab->die == 1)
		return (put_fork_down(philo->rfork, NULL));
	print_log(philo->tab, philo->id, "has taken a fork");
	if (philo->rfork == philo->lfork)
		return (put_fork_down(philo->rfork, NULL));
	pthread_mutex_lock(philo->lfork);
	if (philo->tab->die == 1)
		return (put_fork_down(philo->rfork, philo->lfork));
	print_log(philo->tab, philo->id, "has taken a fork");
	philo->last_eat = get_ltime();
	return ((void *)philo);
}