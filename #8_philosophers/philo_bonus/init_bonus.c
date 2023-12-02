/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:24:37 by ateow             #+#    #+#             */
/*   Updated: 2023/12/02 16:24:38 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	pthread_mutex_init(&(data->print), NULL);
	data->start_time = timestamp();
	return (0);
}

void	init_philo(t_vars *data, int i)
{
	data->philo[i].id = i;
	data->philo[i].count_eat = 0;
	data->philo[i].last_ate = timestamp();
	data->philo[i].hold_forks = 0;
	data->philo[i].is_thinking = 1;
	data->philo[i].data = data;
	pthread_mutex_init(&(data->fork[i]), NULL);
	pthread_mutex_init(&(data->philo[i].eating), NULL);
}
