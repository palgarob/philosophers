/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:51:55 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/10 03:07:35 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	notify(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->lunch->mut_notify);
	if (!philo->lunch->funeral || message[0] == DIED[0])
		printf("%lu %d %s\n", get_time() - philo->lunch->start_time,
			philo->id, message);
	pthread_mutex_unlock(&philo->lunch->mut_notify);
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
	notify(philo, TAKE_FORK);
	ft_usleep(philo->lunch->t_die + 1);
	philo->lunch->funeral = true;
	notify(philo, DIED);
	return (true);
}
