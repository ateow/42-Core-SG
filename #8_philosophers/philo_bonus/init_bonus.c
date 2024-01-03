/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:24:37 by ateow             #+#    #+#             */
/*   Updated: 2024/01/03 21:29:27 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_vars *data, char **argv)
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
	data->start_time = timestamp();
	data->child_pid = malloc(sizeof(int) * data->n_philo);
	unlink_sem();
	init_sem(data);
}

void	init_philo(t_vars *data, int i)
{
	data->philo[i].id = i;
	data->philo[i].count_eat = 0;
	data->philo[i].last_ate = timestamp();
	data->philo[i].hold_forks = 0;
	data->philo[i].is_thinking = 1;
	data->philo[i].data = data;
}

void	init_sem(t_vars *data)
{
	data->terminate = sem_open("/terminate", O_CREAT | O_EXCL, 0666, 0);
	data->sem_end_sim = sem_open("/sem_end_sim", O_CREAT | O_EXCL, 0666, 0);
	data->sem_is_full = sem_open("/sem_is_full", O_CREAT | O_EXCL, 0666, 0);
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, 0666, data->n_philo);
	data->print = sem_open("/print", O_CREAT | O_EXCL, 0666, 1);
}

void	unlink_sem(void)
{
	sem_unlink("/sem_end_sim");
	sem_unlink("/sem_is_full");
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/terminate");
}

void	close_sem(t_vars *data)
{
	sem_close(data->sem_end_sim);
	sem_close(data->print);
	sem_close(data->forks);
	sem_close(data->sem_is_full);
	sem_close(data->terminate);
	unlink_sem();
}
