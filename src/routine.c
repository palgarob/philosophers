/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:19 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/13 11:45:22 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo)
{
	if (party_of_one(philo))
		return ;
	pthread_mutex_lock(philo->r_fork);
	notify(philo, TAKE_FORK);
	pthread_mutex_lock(philo->l_fork);
	notify(philo, TAKE_FORK);
	notify(philo, EAT);
	getset_t_last_ate(philo, 1);
	getset_n_meals_had(philo, 1);
	ft_usleep(philo->lunch->t_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	sleeping(t_philo *philo)
{
	notify(philo, SLEEP);
	ft_usleep(philo->lunch->t_sleep);
}

static void	thinking(t_philo *philo)
{
	notify(philo, THINK);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 0)
		ft_usleep(philo->lunch->t_eat - 10);
	while (!getset_funeral(philo->lunch, 0))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
