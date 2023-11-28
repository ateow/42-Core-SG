#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef	struct	s_status
{
   	pthread_t tid;
	int	id;
	int	pax;
	int	fork_left;
	int	fork_right;
	int	eat;
	int	think;
	int	dead;
}	t_status;

int	all_dead(t_status *philo);
int	ft_atoi(const char *str);

#endif
