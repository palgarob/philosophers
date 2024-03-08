/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:19 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/08 17:39:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo)
{
	if (party_of_one(philo))
		return ;
	pthread_mutex_lock(philo->r_fork);
	if (getset_funeral(philo->lunch, 0))
	{
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	notify(philo, TAKE_RFORK);
	pthread_mutex_lock(philo->l_fork);
	if (getset_funeral(philo->lunch, 0))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	notify(philo, TAKE_LFORK);
	notify(philo, EAT);
	philo->t_last_ate = get_time();
	philo->n_meals_had++;
	ft_usleep(philo->lunch->t_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	sleeping(t_philo *philo)
{
	if (getset_funeral(philo->lunch, 0))
		return ;
	notify(philo, SLEEP);
	ft_usleep(philo->lunch->t_sleep);
}

static void	thinking(t_philo *philo)
{
	if (getset_funeral(philo->lunch, 0))
		return ;
	notify(philo, THINK);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	philo->t_last_ate = philo->lunch->start_time;
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
