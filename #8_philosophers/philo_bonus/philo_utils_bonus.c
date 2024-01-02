/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:37:07 by ateow             #+#    #+#             */
/*   Updated: 2023/12/02 15:37:08 by ateow            ###   ########.fr       */
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
	time = timestamp() - philo->data->start_time;
	if (health == 1 && philo->data->end_sim != 1)
		printf("%ld %d %s\n", time, philo->id + 1, str);
	else if (health == 0)
		printf("%ld %d %s\n", time, philo->id + 1, str);
	sem_post(philo->data->print);
}

// void	free_all(t_vars *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->n_philo)
// 	{
// 		pthread_mutex_destroy(&(data->fork[i]));
// 		pthread_mutex_destroy(&(data->philo[i].eating));
// 		i++;
// 	}
// 	pthread_mutex_destroy(&(data->print));
// 	free(data->philo);
// 	free(data->fork);
// }
