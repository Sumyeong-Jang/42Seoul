#include "../include/philosophers.h"
#include <string.h>
#include <stdlib.h>

void	clear_table(t_table *table);

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	die_check;

	memset(&table, 0, sizeof(t_table));
	if (check_args(argc, argv, &table) == FALSE)
		return (str_error("Error : Invalid Arguments!", 1));
	if (table.noe == 0 || table.nop == 0)
		return (0);
	if (init_philosophers(&table) == FALSE)
		return (str_error("Error : Fail to set table", 1));
	if (!pthread_create(&die_check, NULL, check_terminate, &table))
	{
		if (init_thread(&table) == FALSE)
			return (str_error("Error : Fail to start dining", 1));
		pthread_join(die_check, NULL);
	}
	clear_table(&table);
	return (0);
}

void	clear_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nop)
	{
		if (table->philos[i].phil_thread != 0)
			pthread_join(table->philos[i].phil_thread, NULL);
	}
	i = -1;
	while (++i < table->nop)
		pthread_mutex_destroy(&(table->forks[i]));
	pthread_mutex_destroy(&(table->log));
	pthread_mutex_destroy(&(table->eat));
	pthread_mutex_destroy(&(table->die_check));
	free(table->philos);
	free(table->forks);
}