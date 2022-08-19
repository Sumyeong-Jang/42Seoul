#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# define TRUE 1
# define FALSE 0

typedef pthread_mutex_t	t_mutex;

struct					s_table;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_eat;
	t_mutex			*lfork;
	t_mutex			*rfork;
	t_mutex			*phil_log;
	struct s_table	*tab;
	pthread_t		phil_thread;
}					t_philo;

typedef struct s_table
{
	int			nop;
	long		t2d;
	long		t2e;
	long		t2s;
	int			noe;
	int			die;
	int			full;
	long		start;
	t_philo		*philos;
	t_mutex		*forks;
	t_mutex		die_check;
	t_mutex		log;
	t_mutex		eat;
}				t_table;

/*utils*/
long	ft_atou(char *str);
int		str_error(char *str, int ret);
void	print_log(t_table *table, int philosopher_id, char *message);
long	get_ltime(void);
void	mili_sleep(long msec);

/*preprocess*/
int		check_args(int argc, char **argv, t_table *table);
int		init_philosophers(t_table *table);
int		init_thread(t_table *table);
void	clear_table(t_table *table);

/*philosopher*/
void	*start_dining(void *vargp);
void	*check_terminate(void *vargp);
void	*put_fork_down(t_mutex *lfork, t_mutex *rfork);
void	*pick_fork_up(t_philo *philo);

#endif