/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:31:06 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/06 18:56:46 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_funeral(t_lunch *lunch, int arrange)
{
	int	fun;

	fun = 0;
	pthread_mutex_lock(&lunch->mut_funeral);
	if (arrange)
		lunch->funeral = 1;
	else
		fun = lunch->funeral;
	pthread_mutex_unlock(&lunch->mut_funeral);
	return (fun);
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
