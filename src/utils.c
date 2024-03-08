/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:51:55 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/06 18:31:52 by pepaloma         ###   ########.fr       */
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
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(unsigned long sleep_time)
{
	unsigned long	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

void	handle_1_philo(t_philo *philo)
{
	notify(philo, TAKE_FORKS);
	ft_usleep(philo->lunch->t_die + 1);
	check_funeral(philo->lunch, 1);
	notify(philo, DIED);
}
