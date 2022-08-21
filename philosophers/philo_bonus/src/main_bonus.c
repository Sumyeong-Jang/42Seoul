#include "philosopher_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (check_args(argc, argv, &table) == FALSE)
		return (str_error("Error : Invalid Arguments!", 1));
	if (init_table(&table) == FALSE)
		return (str_error("Error : Fail to set table", 1));
	if (init_philosophers(&table) == FALSE)
		return (str_error("Error : Fail to set Philos", 1));
	clear_table(&table);
	return (0);
}

void	clear_table(t_table *table)
{
	while (table->philo_cnt > 0)
	{
		waitpid(table->philo_pid[table->philo_cnt], NULL, 0);
		usleep(10);
		table->philo_cnt--;
	}
	sem_close(table->forks_sem);
	sem_close(table->die_sem);
	sem_close(table->log_sem);
	sem_close(table->eat_sem);
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(DIE_SEM_NAME);
	sem_unlink(LOG_SEM_NAME);
	sem_unlink(EAT_SEM_NAME);
	free(table->philo_pid);
}
