/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:19 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/10 02:38:52 by pepaloma         ###   ########.fr       */
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
	philo->t_last_ate = get_time();
	philo->n_meals_had++;
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
	while (!philo->lunch->funeral)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
