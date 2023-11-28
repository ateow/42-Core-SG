#include "philo.h"

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

int	all_dead(t_status *philo)
{
	int	i;
	int	c;
	
	i = 0;
	c = 0;
	while(i < philo[0].pax)
	{
		if (philo[i].dead == 1)
			c++;
		i++;
	}
	if (c == philo[0].pax)
		return(1);
	else
		return(0);
}
