/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:38:14 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/10 02:42:38 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// memset
# include <string.h>
// printf
# include <stdio.h>
// malloc free
# include <stdlib.h>
// write usleep
# include <unistd.h>
// gettimeofday
# include <sys/time.h>
// pthread
# include <pthread.h>
// INT_MIN INT_MAX
# include <limits.h>
// bool
# include <stdbool.h>

# define ERROR_ARGNUM "The number of arguments must be 4 or 5\n"
# define ERROR_ONLY_NUM "Only numeric values are accepted\n"
# define ERROR_VALUES "The number_of_philosophers and \
number_of_times_each_philosopher_must_eat parameters must be greater than 0\n"
# define ERROR_THREAD_CREATE "An error occurred when creating a thread"
# define ERROR_THREAD_JOIN "An error occurred when joining a thread"
# define ERROR_MALLOC "There was an error when allocating memory"
# define ERROR_MUTEX_INIT "An error occurred when initializing a mutex"
# define ERROR_MUTEX_DEST "An error occurred when destroying a mutex"

# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef struct s_philo
{
	struct s_lunch	*lunch;
	int				id;
	unsigned long	t_last_ate;
	int				n_meals_had;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_lunch
{
	int				n_philos;
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	int				must_eat;
	unsigned long	start_time;
	bool			funeral;
	t_philo			*philos;
	pthread_t		monitor_life;
	pthread_t		monitor_full;
	pthread_mutex_t	mut_notify;
	pthread_mutex_t	*forks;
}	t_lunch;

int				parse_args(int argc, char **argv, t_lunch *lunch);
int				init_lunch(t_lunch *lunch);

void			free_mallocs(t_lunch *lunch);
void			clear_lunch(t_lunch *lunch);

int				philo(t_lunch *lunch);
void			*routine(void *param);
void			*monitor_life(void *param);
void			*monitor_full(void *param);

unsigned long	get_time(void);
void			ft_usleep(unsigned long sleep_time);
void			notify(t_philo *philo, char *message);
bool			party_of_one(t_philo *philo);
#endif
