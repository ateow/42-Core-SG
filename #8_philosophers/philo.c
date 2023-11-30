#include "philo.h"

# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"



int	init_data(t_vars *data, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->end_sim = 0;
	data->n_eat = -1;
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	data->fork_status = malloc(sizeof(int) * data->n_philo);
	pthread_mutex_init(&(data->check_fork), NULL);
	data->start_time = timestamp();
	return(0);
}

void	init_philo(t_vars *data, int i)
{
	data->philo[i].id = i;
	data->philo[i].count_eat = 0;
	data->philo[i].last_ate = -1;
	data->philo[i].hold_forks = 0;
	if (data->philo[i].id % 2)
		data->philo[i].is_thinking = 0;
	else
		data->philo[i].is_thinking = 1;
	data->philo[i].data = data;
	data->fork_status[i] = 1;
	pthread_mutex_init(&(data->fork[i]), NULL);
	pthread_mutex_init(&(data->philo[i].eating), NULL);
}

void	*check_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while(philo->data->end_sim != 1)
	{
		pthread_mutex_lock(&philo->eating);
		if ((timestamp() - philo->last_ate) > philo->data->time_die && philo->data->end_sim != 1)
		{
			philo->data->end_sim = 1;
			printf("%ld %d died\n", timestamp() - philo->data->start_time, philo->id + 1);
		}
		pthread_mutex_unlock(&philo->eating);
		ft_usleep(1);
	}
	return (NULL);
}
/*
void	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	if ((timestamp() - philo->last_ate) > philo->data->time_die && philo->data->end_sim != 1)
	{
		philo->data->end_sim = 1;
		printf("%ld %d died\n", timestamp() - philo->data->start_time, philo->id + 1);
	}
	pthread_mutex_unlock(&philo->eating);
}*/

void	check_eat_count(t_philo *philo)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (philo->data->n_eat > 0)
	{
		while(i < philo->data->n_philo)
		{
			if (philo->data->philo[i].count_eat >= philo->data->n_eat)
				count++;
			i++;
		}
		if (count == philo->data->n_philo)
			philo->data->end_sim = 1;
	}
}

void	eat_sleep(t_philo *philo)
{
	//eat
	pthread_mutex_lock(&philo->eating);
	philo->count_eat = philo->count_eat + 1;
	printf("%ld %d is eating\n",timestamp() - philo->data->start_time, philo->id + 1);
	check_eat_count(philo);
	philo->last_ate = timestamp();
	ft_usleep(philo->data->time_eat);
	
	//realease fork
	if ((philo->id + 1) != philo->data->n_philo)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->id]);
		philo->data->fork_status[philo->id] = 1;
		pthread_mutex_unlock(&philo->data->fork[philo->id + 1]);
		philo->data->fork_status[philo->id + 1] = 1;
	}
	else
	{
		pthread_mutex_unlock(&philo->data->fork[0]);
		philo->data->fork_status[0] = 1;
		pthread_mutex_unlock(&philo->data->fork[philo->id]);
		philo->data->fork_status[philo->id] = 1;
	}
	philo->hold_forks = 0;
	pthread_mutex_unlock(&philo->eating);
	//sleep
	if (philo->data->end_sim != 1)
	{
		printf("%ld %d is sleeping\n", timestamp() - philo->data->start_time, philo->id + 1);
		ft_usleep(philo->data->time_sleep);
	}
}

int	check_forks(t_philo *philo)
{
		if ((philo->id + 1) != philo->data->n_philo)
		{
			if (philo->data->fork_status[philo->id] == 1 && philo->data->fork_status[philo->id + 1] == 1)
				return (1);
			return (0);
		}
		else
		{
			if (philo->data->fork_status[philo->id] == 1 && philo->data->fork_status[0] == 1)
				return (1);
			return (0);
		}
}

void	get_first_fork(t_philo *philo)
{
	if ((philo->id + 1) != philo->data->n_philo)
	{
		pthread_mutex_lock(&philo->data->fork[philo->id]);
		philo->data->fork_status[philo->id] = 0;
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork[0]);
		philo->data->fork_status[0] = 0;
	}
	if (philo->data->end_sim != 1)
	{
		printf("%ld %d has taken a fork\n", timestamp() - philo->data->start_time, philo->id + 1);
	}
}

void	get_second_fork(t_philo *philo)
{
	if ((philo->id + 1) != philo->data->n_philo)
	{
		pthread_mutex_lock(&philo->data->fork[philo->id + 1]);
		philo->data->fork_status[philo->id + 1] = 0;
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork[philo->id]);
		philo->data->fork_status[philo->id] = 0;
	}
	if (philo->data->end_sim != 1)
	{
		printf("%ld %d has taken a fork\n", timestamp() - philo->data->start_time, philo->id + 1);
	}
}

void	*philo_life(void *data)
{
	t_philo	*philo;
	pthread_t	health_tid;

	philo = (t_philo *)data;
	philo->last_ate = timestamp();

	pthread_create(&health_tid, NULL, check_death, philo);
	while(philo->data->end_sim != 1)
	{
		if (philo->hold_forks == 1)
		{
			eat_sleep(philo);
			philo->is_thinking = 1;
		}
		else if (philo->hold_forks == 0 && philo->is_thinking == 0)
		{
			get_first_fork(philo);
			get_second_fork(philo);
			philo->hold_forks = 1;
		}		
		else if (philo->is_thinking == 1)
		{
			printf("%ld %d is thinking\n", timestamp() - philo->data->start_time, philo->id + 1);
			philo->is_thinking = 0;
			ft_usleep(2);
		}
	}
	return (NULL);
}

int	main(int argc, char* argv[])
{
	t_vars	data;
	int	i;
	
	if (argc < 5 || (argv[5] && ft_atoi(argv[5]) == 0))
		return(0);
	init_data(&data, argv);
	i = 0;
	while(i < data.n_philo)
	{
		init_philo(&data, i);
		pthread_create(&data.philo[i].thread, NULL, philo_life, &(data.philo[i]));
		i++;
	}
	i = 0;
	while(i < data.n_philo)
	{
		pthread_join(data.philo[i].thread, NULL);
		i++;
	}
	return (1);
}

