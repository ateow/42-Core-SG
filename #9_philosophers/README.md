# philosophers

This project is about creating a program to resolve the "dining philosophers" problem.
Program takes in the following arguments: 
* number_of_philosophers
* time_to_die
* time_to_eat
* time_to_sleep
* number_of_times_each_philosoher_must_eat (optional)

Rules:
* One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
* The philosophers alternatively eat, think, or sleep.
  * While they are eating, they are not thinking nor sleeping;
  * while thinking, they are not eating nor sleeping;
  * and, of course, while sleeping, they are not eating nor thinking.
* There are also forks on the table. There are as many forks as philosophers.
* Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
* When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
* Every philosopher needs to eat and should never starve.
* Philosophers don’t speak with each other.
* Philosophers don’t know if another philosopher is about to die.
* No need to say that philosophers should avoid dying!
* A displayed state message should not be mixed up with another message.
* A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.
* Any state change of a philosopher must be formatted as follows:
  * timestamp_in_ms X has taken a fork
  * timestamp_in_ms X is eating
  * timestamp_in_ms X is sleeping
  * timestamp_in_ms X is thinking
  * timestamp_in_ms X died

### Mandatory (solve with threads)
The specific rules for the mandatory part are:
• Each philosopher should be a thread.
• There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
• To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

### Bonus (solve with processes)
The specific rules for the bonus part are:
• All the forks are put in the middle of the table.
• They have no states in memory but the number of available forks is represented by a semaphore.
• Each philosopher should be a process. But the main process should not be a philosopher.
