/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:39:55 by ateow             #+#    #+#             */
/*   Updated: 2024/01/03 22:08:57 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>

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
	sem_t			*sem_end_sim;
	sem_t			*sem_is_full;
	sem_t			*terminate;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*eat;
	int				*child_pid;
}	t_vars;

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				hold_forks;
	int				is_thinking;
	long int		last_ate;
	t_vars			*data;
}	t_philo;

void		init_data(t_vars *data, char **argv);
void		init_philo(t_vars *data, int i);
void		init_sem(t_vars *data);
long int	timestamp(void);
int			ft_atoi(const char *str);
void		print(t_philo *philo, char *str, int health);
void		unlink_sem(void);
void		close_sem(t_vars *data);
void		*check_full(void *data);
void		*end_process(void *data);

#endif
