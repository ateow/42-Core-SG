#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef	struct	s_vars
{
	int	n_philo;
	int	n_eat;
	int	time_sleep;
	int	time_die;
	int	time_eat;
	int	end_sim;
	long int	start_time;
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	check_fork;
	int	*fork_status;
}	t_vars;

typedef	struct	s_philo
{
	int	id;
	pthread_t		thread;

	pthread_mutex_t	eating;
	int	count_eat;
	long int	last_ate;

	int	hold_forks;
	int	is_thinking;

	t_vars	*data;
}	t_philo;

long int	timestamp(void);
void	ft_usleep(int ms);
int	ft_atoi(const char *str);
void	*thread_routine(void *data);

#endif
