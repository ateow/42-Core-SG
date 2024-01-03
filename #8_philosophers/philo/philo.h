/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:55 by ateow             #+#    #+#             */
/*   Updated: 2024/01/03 21:06:03 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_vars
{
	struct s_philo	*philo;
	int				n_philo;
	int				n_eat;
	int				time_sleep;
	int				time_die;
	int				time_eat;
	int				end_sim;
	long int		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_vars;

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				hold_forks;
	int				is_thinking;
	long int		last_ate;
	pthread_t		thread;
	pthread_mutex_t	eating;
	t_vars			*data;
}	t_philo;

int			init_data(t_vars *data, char **argv);
void		init_philo(t_vars *data, int i);
long int	timestamp(void);
void		ft_usleep(int ms);
int			ft_atoi(const char *str);
void		*thread_routine(void *data);
void		print(t_philo *philo, char *str, int health);
void		free_all(t_vars *data);

#endif
