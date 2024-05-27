/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:00 by ateow             #+#    #+#             */
/*   Updated: 2024/01/03 21:58:32 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	print(philo, "is eating", 1);
	philo->last_ate = timestamp();
	usleep(philo->data->time_eat * 1000);
	philo->count_eat = philo->count_eat + 1;
	if ((philo->id + 1) != philo->data->n_philo)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->id]);
		pthread_mutex_unlock(&philo->data->fork[philo->id + 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->fork[0]);
		pthread_mutex_unlock(&philo->data->fork[philo->id]);
	}
	pthread_mutex_unlock(&philo->eating);
	philo->hold_forks = 0;
	if (philo->data->end_sim != 1)
	{
		print(philo, "is sleeping", 1);
		usleep(philo->data->time_sleep * 1000);
	}
}

void	get_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->data->fork[philo->id]);
		print(philo, "has taken a fork", 1);
		if ((philo->id + 1) != philo->data->n_philo)
			pthread_mutex_lock(&philo->data->fork[philo->id + 1]);
		else
			pthread_mutex_lock(&philo->data->fork[0]);
		print(philo, "has taken a fork", 1);
	}
	else if (philo->id % 2 == 0)
	{
		if ((philo->id + 1) != philo->data->n_philo)
			pthread_mutex_lock(&philo->data->fork[philo->id + 1]);
		else
			pthread_mutex_lock(&philo->data->fork[0]);
		print(philo, "has taken a fork", 1);
		pthread_mutex_lock(&philo->data->fork[philo->id]);
		print(philo, "has taken a fork", 1);
	}
}

void	*philo_life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->data->end_sim == 0)
	{
		if (philo->hold_forks == 1)
		{
			eat_sleep(philo);
			philo->is_thinking = 1;
		}
		else if (philo->hold_forks == 0 && philo->is_thinking == 0
			&& philo->data->n_philo > 1)
		{
			get_forks(philo);
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

void	check_end_sim(t_vars *data)
{
	int	i;
	int	count;

	i = 0;
	while (data->end_sim != 1)
	{
		count = 0;
		while (i < data->n_philo)
		{
			if ((timestamp() - data->philo[i].last_ate) > data->time_die 
				&& data->end_sim != 1)
			{
				pthread_mutex_lock(&data->philo[i].eating);
				data->end_sim = 1;
				print(data->philo, "died", 0);
				pthread_mutex_unlock(&data->philo[i].eating);
			}
			if (data->n_eat != -1 && data->philo[i].count_eat >= data->n_eat)
				count++;
			i++;
		}
		i = 0;
		if (data->n_eat != -1 && count == data->n_philo)
			data->end_sim = 1;
	}
}

int	main(int argc, char *argv[])
{
	t_vars	data;
	int		i;

	if (argc < 5 || (argv[5] && ft_atoi(argv[5]) <= 0) || ft_atoi(argv[1]) < 1 
		|| ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (0);
	init_data(&data, argv);
	i = 0;
	while (i < data.n_philo)
	{
		init_philo(&data, i);
		pthread_create(&data.philo[i].thread, NULL,
			philo_life, &(data.philo[i]));
		i++;
	}
	i = 0;
	check_end_sim(&data);
	while (i < data.n_philo)
	{
		pthread_join(data.philo[i].thread, NULL);
		i++;
	}
	free_all(&data);
	return (1);
}

/*
void	*check_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while(philo->data->end_sim != 1)
	{
		pthread_mutex_lock(&philo->eating);
		if ((timestamp() - philo->last_ate) > philo->data->time_die
			&& philo->data->end_sim != 1)
		{
			philo->data->end_sim = 1;
			print(philo, "died", 0);
		}
		pthread_mutex_unlock(&philo->eating);
		ft_usleep(5);
	}
	return (NULL);
}

void	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	if ((timestamp() - philo->last_ate) > philo->data->time_die
		&& philo->data->end_sim != 1)
	{
		philo->data->end_sim = 1;
		print(philo, "died", 0);
	}
	pthread_mutex_unlock(&philo->eating);
}
*/
/*
int	check_forks(t_philo *philo)
{
		if ((philo->id + 1) != philo->data->n_philo)
		{
			if (philo->data->fork_status[philo->id] == 1
				&& philo->data->fork_status[philo->id + 1] == 1)
				return (1);
			return (0);
		}
		else
		{
			if (philo->data->fork_status[philo->id] == 1
				&& philo->data->fork_status[0] == 1)
				return (1);
			return (0);
		}
}*/
