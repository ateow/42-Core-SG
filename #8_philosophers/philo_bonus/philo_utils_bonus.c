/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:07 by ateow             #+#    #+#             */
/*   Updated: 2024/01/03 21:37:33 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	n;

	i = 0;
	res = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * n);
}

long int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print(t_philo *philo, char *str, int health)
{
	long int	time;

	sem_wait(philo->data->print);
	if (health == 0)
		usleep(2000);
	time = timestamp() - philo->data->start_time;
	if (health == 1 && philo->data->end_sim != 1)
		printf("%ld %d %s\n", time, philo->id + 1, str);
	else if (health == 0 && philo->data->end_sim != 1)
		printf("%ld %d %s\n", time, philo->id + 1, str);
	sem_post(philo->data->print);
}

void	*check_full(void *data)
{
	t_vars	*philo;
	int		i;

	i = 0;
	philo = (t_vars *)data;
	while (i < philo->n_philo && philo->end_sim != 1)
	{
		sem_wait(philo->sem_is_full);
		i++;
	}
	philo->end_sim = 1;
	sem_post(philo->sem_end_sim);
	return (NULL);
}

void	*end_process(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	sem_wait(philo->data->sem_end_sim);
	philo->data->end_sim = 1;
	sem_post(philo->data->sem_end_sim);
	sem_post(philo->data->terminate);
	return (NULL);
}
