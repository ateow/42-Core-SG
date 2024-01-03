/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:00 by ateow             #+#    #+#             */
/*   Updated: 2024/01/03 22:09:39 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo_bonus.h"

#include "philo_bonus.h"

void	eat_sleep(t_philo *philo, sem_t *forks)
{
	sem_wait(philo->data->eat);
	if (philo->data->end_sim != 1)
	{
		sem_post(philo->data->eat);
		print(philo, "is eating", 1);
		philo->last_ate = timestamp();
		usleep(philo->data->time_eat * 1000);
		philo->count_eat = philo->count_eat + 1;
		if (philo->count_eat == philo->data->n_eat)
			sem_post(philo->data->sem_is_full);
		sem_post(forks);
		sem_post(forks);
		philo->hold_forks = 0;
		if (philo->data->end_sim != 1)
		{
			print(philo, "is sleeping", 1);
			usleep(philo->data->time_sleep * 1000);
		}
		philo->is_thinking = 1;
	}
}

void	*philo_thread(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->data->end_sim != 1)
	{
		if (philo->hold_forks == 1)
		{
			eat_sleep(philo, philo->data->forks);
		}
		else if (philo->hold_forks == 0 && philo->is_thinking == 0
			&& philo->data->n_philo > 1)
		{
			sem_wait(philo->data->forks);
			sem_wait(philo->data->forks);
			philo->hold_forks = 1;
		}
		else if (philo->is_thinking == 1)
		{
			print(philo, "is thinking", 1);
			philo->is_thinking = 0;
			usleep(2 * 1000);
		}
	}
	return (NULL);
}

void	*philo_life(t_philo *philo)
{
	pthread_t	health_thread;
	pthread_t	end_thread;

	pthread_create(&health_thread, NULL, philo_thread, philo);
	pthread_create(&end_thread, NULL, end_process, philo);
	while (philo->data->end_sim != 1)
	{
		if ((timestamp() - philo->last_ate) > philo->data->time_die)
		{
			sem_wait(philo->data->eat);
			print(philo, "died", 0);
			philo->data->end_sim = 1;
			sem_post(philo->data->sem_end_sim);
			sem_post(philo->data->eat);
			break ;
		}
	}
	pthread_join(end_thread, NULL);
	pthread_join(health_thread, NULL);
	close_sem(philo->data);
	free(philo->data->child_pid);
	free(philo->data->philo);
	exit(1);
}

void	fork_and_execute(t_vars	*data, int i)
{
	data->child_pid[i] = fork();
	if (data->child_pid[i] == 0)
	{
		init_philo(data, i);
		philo_life(&(data->philo[i]));
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_vars		data;
	pthread_t	full_thread;

	if (argc < 5 || (argv[5] && ft_atoi(argv[5]) <= 0) || ft_atoi(argv[1]) < 1
		|| ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (0);
	init_data(&data, argv);
	i = -1;
	while (++i < data.n_philo)
		fork_and_execute(&data, i);
	if (data.n_eat != -1 && data.n_philo > 2)
		pthread_create(&full_thread, NULL, check_full, &data);
	while (i-- > 0)
		sem_wait(data.terminate);
	if (data.n_eat != -1 && data.n_philo > 2)
	{
		data.end_sim = 1;
		sem_post(data.sem_is_full);
		pthread_join(full_thread, NULL);
	}
	free(data.child_pid);
	free(data.philo);
	close_sem(&data);
	return (1);
}
