/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:06:28 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/10 14:52:47 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_life(void *param)
{
	t_lunch	*lunch;
	int		i;

	lunch = (t_lunch *)param;
	while (1)
	{
		if (getset_funeral(lunch, 0))
			return (NULL);
		i = -1;
		while (++i < lunch->n_philos)
		{
			if (get_time() - getset_last_ate(&lunch->philos[i], 0)
				> lunch->t_die)
			{
				getset_funeral(lunch, 1);
				if (lunch->n_philos != 1)
					notify(&lunch->philos[i], DIED);
				return (NULL);
			}
		}
		ft_usleep(1);
	}
	return (NULL);
}

static bool	all_are_full(t_lunch *lunch)
{
	int			i;

	i = -1;
	while (++i < lunch->n_philos)
	{
		if (getset_n_meals_had(&lunch->philos[i], 0) < lunch->must_eat)
			return (false);
	}
	return (true);
}

void	*monitor_full(void *param)
{
	t_lunch	*lunch;

	lunch = (t_lunch *)param;
	while (1)
	{
		if (getset_funeral(lunch, 0))
			return (NULL);
		if (all_are_full(lunch))
			return (getset_funeral(lunch, 1), NULL);
		ft_usleep(1);
	}
	return (NULL);
}
