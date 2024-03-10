/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:32:34 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/10 14:33:14 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	getset_last_ate(t_philo *philo, bool set)
{
	unsigned long	t_last_ate;

	t_last_ate = 0;
	pthread_mutex_lock(&philo->mut_last_ate);
	if (set)
		philo->t_last_ate = get_time();
	else
		t_last_ate = philo->t_last_ate;
	pthread_mutex_unlock(&philo->mut_last_ate);
	return (t_last_ate);
}

int	getset_n_meals_had(t_philo *philo, bool set)
{
	int	n_meals_had;

	n_meals_had = 0;
	pthread_mutex_lock(&philo->mut_n_meals_had);
	if (set)
		philo->n_meals_had++;
	else
		n_meals_had = philo->n_meals_had;
	pthread_mutex_unlock(&philo->mut_n_meals_had);
	return (n_meals_had);
}

bool	getset_funeral(t_lunch *lunch, bool set)
{
	bool	funeral;

	funeral = false;
	pthread_mutex_lock(&lunch->mut_funeral);
	if (set)
		lunch->funeral = true;
	else
		funeral = lunch->funeral;
	pthread_mutex_unlock(&lunch->mut_funeral);
	return (funeral);
}
