/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:51:55 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/08 18:15:58 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	notify(t_philo *philo, char *message)
{
	printf(
		"%lu %d %s\n",
		get_time() - philo->lunch->start_time,
		philo->id,
		message
	);
}

unsigned long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("WHAT");
		return (0);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(unsigned long sleep_time)
{
	unsigned long	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

bool	party_of_one(t_philo *philo)
{
	if (philo->lunch->n_philos != 1)
		return (false);
	notify(philo, TAKE_RFORK);
	ft_usleep(philo->lunch->t_die + 1);
	getset_funeral(philo->lunch, 1);
	notify(philo, DIED);
	return (true);
}

int	getset_funeral(t_lunch *lunch, int set)
{
	int	funeral;

	funeral = 0;
	pthread_mutex_lock(&lunch->mut_funeral);
	if (set)
		lunch->funeral = 1;
	else
		funeral = lunch->funeral;
	pthread_mutex_unlock(&lunch->mut_funeral);
	return (funeral);
}

/* int	check_last_ate(t_philo *philo, int update)
{
	int	alive;

	alive = 1;
	pthread_mutex_lock(&philo->mut_last_ate);
	if (update)
		philo->t_last_ate = get_time();
	else
		if (get_time() - philo->t_last_ate > philo->lunch->t_die)
			alive = 0;
	pthread_mutex_unlock(&philo->mut_last_ate);
	return (alive);
} */
