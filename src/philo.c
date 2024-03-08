/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:49:25 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/08 15:08:07 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	run_threads(t_lunch *lunch)
{
	int	i;

	i = -1;
	lunch->start_time = get_time();
	while (++i < lunch->n_philos)
	{
		if (pthread_create(&lunch->philos[i].thread, NULL, routine, &lunch->philos[i]))
			return (printf(ERROR_THREAD_CREATE), 1);
	}
	if (pthread_create(&lunch->monitor_life, NULL, monitor_life, lunch))
		return (printf(ERROR_THREAD_CREATE), 1);
	if (lunch->must_eat != -1 && pthread_create(&lunch->monitor_full, NULL, monitor_full, lunch))
		return (printf(ERROR_THREAD_CREATE), 1);
	return (0);
}

static int	join_threads(t_lunch *lunch)
{
	int	i;

	if (pthread_join(lunch->monitor_life, NULL))
		return (printf(ERROR_THREAD_JOIN), 1);
	if (lunch->must_eat != -1 && pthread_join(lunch->monitor_full, NULL))
		return (printf(ERROR_THREAD_JOIN), 1);
	i = -1;
	while (++i < lunch->n_philos)
	{
		if (pthread_join(lunch->philos[i].thread, NULL))
			return (printf(ERROR_THREAD_JOIN), 1);
	}
	return (0);
}

int	philo(t_lunch *lunch)
{
	if (run_threads(lunch))
		return (clear_lunch(lunch), 1);
	if (join_threads(lunch))
		return (clear_lunch(lunch), 1);
	clear_lunch(lunch);
	return (0);
}
