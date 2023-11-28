#include "philo.h"

# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"



void	initi(int *fork_status, t_status *philo, int pax)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while(i < pax)
	{
		philo[i].fork_left = 0;
		philo[i].fork_right = 0;
		philo[i].eat = 0;
		philo[i].think = 0;
		philo[i].dead = 0;
		philo[i].pax = pax;
		i++;
	}	
	i = 0;
	while(i < pax)
	{
		fork_status[i] = 0;
		i++;
	}
}

// thread_routine is the function the thread invokes right after its
// creation. The thread ends at the end of this function.
void	*thread_routine(void *data)
{
	t_status *philo;
	philo = (t_status *)data;

	printf("entering\n");
	while(all_dead(philo) != 1)
	{
		philo[0].dead = 1;
		printf("philo dead: %d\n", philo[0].dead);
		philo[1].dead = 1;
		printf("philo dead: %d\n", philo[1].dead);
	}
}

int	main(int argc, char* argv[])
{
	int *fork_status;
	int	pax;
	struct timeval tv;
	t_status	*philo;
	
	pax = ft_atoi(argv[1]);

	fork_status = malloc(sizeof(int) * pax);

	philo = malloc(sizeof(t_status) * pax);
	initi(fork_status, philo, pax);

	//pthread_create(&philo[0].tid, NULL, thread_routine, philo);

	pthread_create(&philo[0].tid, NULL, thread_routine, philo);
	gettimeofday(&tv, NULL);
	printf("timestamp:%ld microseconds\n", tv.tv_usec);
	
	/*while(all_dead(philo) != 1)
	{
		pthread_create(&philo[0].tid, NULL, thread_routine, philo);
		gettimeofday(&tv, NULL);
		//printf("timestamp:%ld microseconds\n", tv.tv_usec);
	}*/

	// Creating the first thread that will go
	// execute its thread_routine function.
	//	pthread_create(&tid1, NULL, thread_routine, NULL);
	//	printf("Main: Created first thread [%ld]\n", tid1);
	
	// Creating the second thread that will also execute thread_routine.
	//	pthread_create(&tid2, NULL, thread_routine, NULL);
	//	printf("Main: Created second thread [%ld]\n", tid2);
	
	// The main thread waits for the new threads to end with pthread_join.
	
	//pthread_join(tid1, NULL);
	//printf("Main: Joining first thread [%ld]\n", tid1);
	//pthread_join(tid2, NULL);
	//printf("Main: Joining second thread [%ld]\n", tid2);
	return (0);
}

