/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:00 by ateow             #+#    #+#             */
/*   Updated: 2023/12/02 15:37:02 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t *end_sim;

void	eat_sleep(t_philo *philo, sem_t *forks)
{
	//eat
	print(philo, "is eating", 1);
	philo->last_ate = timestamp();
	usleep(philo->data->time_eat * 1000);
	philo->count_eat = philo->count_eat + 1;
	if (philo->count_eat == philo->data->n_eat)
	{
		// printf(">>>>>>>>>>>>>>>>>>>>>>>>>\n");
		sem_post(philo->data->sem_is_full);
	}
	//realease fork
	sem_post(forks);
	sem_post(forks);
	philo->hold_forks = 0;
	//sleep
	if (philo->data->end_sim != 1)
	{
		print(philo, "is sleeping", 1);
		usleep(philo->data->time_sleep * 1000);
	}
}

void	stop_process(t_vars *data, int *child_pid)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		kill(child_pid[i], SIGTERM);
		i++;
	}
}

void	*check_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while(philo->data->end_sim != 1)
	{
		if ((timestamp() - philo->last_ate) > philo->data->time_die)
		{
			philo->data->end_sim = 1;
			print(philo, "died", 0);
			sem_post(philo->data->sem_end_sim);
		}
	}
	return (NULL);
}



void	*philo_life(void *data, sem_t *forks, sem_t *queue)
{
	t_philo	*philo;
	pthread_t	health_thread;

	philo = (t_philo *)data;
	pthread_create(&health_thread, NULL, check_death, philo);

	while (philo->data->end_sim == 0)
	{
		if (philo->hold_forks == 1)
		{
			eat_sleep(philo, forks);
			philo->is_thinking = 1;
		}
		else if (philo->hold_forks == 0 && philo->is_thinking == 0
			&& philo->data->n_philo > 1)
		{
			sem_wait(queue);
			sem_wait(forks);
			sem_wait(forks);
			sem_post(queue);
			philo->hold_forks = 1;
		}
		else if (philo->is_thinking == 1)
		{
			print(philo, "is thinking", 1);
			philo->is_thinking = 0;
		}
	}
	return (NULL);
}




void	*check_full(void *data)
{
	t_vars	*philo;
	int		i;

	i = 0;
	philo = (t_vars *)data;
	while(i < philo->n_philo)
	{
		// printf("waiting... %d\n", i);
		sem_wait(philo->sem_is_full);
		// printf("<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		i++;
	}
	philo->end_sim = 1;
	sem_post(philo->sem_end_sim);
	return (NULL);
}



int	main(int argc, char *argv[])
{
	t_vars	data;
	int		i;
	pthread_t	full_thread;
	int	*child_pid;
	sem_t 	*forks;
	sem_t 	*queue;

	if (argc < 5 || (argv[5] && ft_atoi(argv[5]) <= 0) || ft_atoi(argv[1]) < 1 
		|| ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (0);	
	init_data(&data, argv);

	sem_unlink("/sem_end_sim");
	sem_unlink("/sem_is_full");
	sem_unlink("/queue");
	sem_unlink("/forks");
	queue = sem_open("/queue", O_CREAT | O_EXCL, 0666, 1);
	data.sem_end_sim = sem_open("/sem_end_sim", O_CREAT | O_EXCL, 0666, 0);
	data.sem_is_full = sem_open("/sem_is_full", O_CREAT | O_EXCL, 0666, 0);
	forks = sem_open("/forks", O_CREAT | O_EXCL, 0666, data.n_philo);

	child_pid = malloc(sizeof(int) * data.n_philo);
	i = 0;
	while (i < data.n_philo)
	{
		child_pid[i] = fork();
		if (child_pid[i] == 0)
		{
			init_philo(&data, i);
			philo_life(&data.philo[i], forks, queue);
			exit (1);
		}
		i++;
	}
	if (data.n_eat != -1)
		pthread_create(&full_thread, NULL, check_full, &data);
	sem_wait(data.sem_end_sim);
	stop_process(&data, child_pid);
	free(data.philo);




	sem_close(data.sem_end_sim);
	sem_unlink("/end_sim");

	sem_close(queue);
	sem_unlink("/queue");

	sem_close(forks);
	sem_unlink("/forks");

	sem_close(data.sem_is_full);
	sem_unlink("/sem_is_full");

	
	return (1);
}
