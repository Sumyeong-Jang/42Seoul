#include "../include/philosophers.h"
#include <stdlib.h>
#include <unistd.h>

int	check_args(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	table->nop = ft_atou(argv[1]);
	table->t2d = ft_atou(argv[2]);
	table->t2e = ft_atou(argv[3]);
	table->t2s = ft_atou(argv[4]);
	if (table->nop < 0 || table->t2d < 0 || table->t2e < 0 || table->t2s < 0)
		return (FALSE);
	table->noe = -1;
	if (argc == 6)
	{
		table->noe = ft_atou(argv[5]);
		if (table->noe < 0)
			return (FALSE);
	}
	return (TRUE);
}

static void	make_philo(t_philo *philo, t_table *table, int i)
{
	philo->id = i + 1;
	philo->eat_count = 0;
	philo->tab = table;
	philo->lfork = table->forks + i;
	philo->rfork = table->forks + ((i + 1) % table->nop);
	philo->last_eat = table->start;
}

int	init_philosophers(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->nop);
	table->forks = malloc(sizeof(t_mutex) * table->nop);
	if (table->philos != NULL && table->forks != NULL)
	{
		table->die = 0;
		table->start = get_ltime();
		i = -1;
		while (++i < table->nop)
		{
			make_philo(table->philos + i, table, i);
			if (pthread_mutex_init(&(table->forks[i]), NULL) != 0)
				return (FALSE);
		}
		if (pthread_mutex_init(&(table->log), NULL) == 0 && \
			pthread_mutex_init(&(table->die_check), NULL) == 0 && \
			pthread_mutex_init(&(table->eat), NULL) == 0)
			return (TRUE);
	}
	return (FALSE);
}

int	init_thread(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->nop)
	{
		if (pthread_create(&(table->philos[i].phil_thread), NULL, \
			start_dining, &(table->philos[i])) != 0)
			return (FALSE);
		i += 2;
		usleep(10);
	}
	i = 1;
	mili_sleep(table->t2e);
	while (i < table->nop && table->die == 0)
	{
		if (pthread_create(&(table->philos[i].phil_thread), NULL, \
			start_dining, &(table->philos[i])) != 0)
			return (FALSE);
		i += 2;
		usleep(10);
	}
	return (TRUE);
}