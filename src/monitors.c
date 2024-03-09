/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:06:28 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/09 22:53:56 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_life(void *param)
{
	t_lunch	*lunch;
	int	i;

	lunch = (t_lunch *)param;
	while (1)
	{
		if (lunch->funeral)
			return (NULL);
		i = -1;
		while (++i < lunch->n_philos)
		{
			if (get_time() - getset_last_ate(&lunch->philos[i], 0) > lunch->t_die)
			{
				lunch->funeral = true;
				if (lunch->n_philos != 1)
					notify(&lunch->philos[i], DIED);
				return (NULL);
			}
		}
		ft_usleep(1);
	}
	return (NULL);
}

void	*monitor_full(void *param)
{
	t_lunch	*lunch;
	int		i;
	int		all_full;

	lunch = (t_lunch *)param;
	while (1)
	{
		if (lunch->funeral)
			return (NULL);
		i = -1;
		all_full = 1;
		while (++i < lunch->n_philos)
		{
			if (lunch->philos[i].n_meals_had < lunch->must_eat)
			{
				all_full = 0;
				break ;
			}
		}
		if (all_full)
		{
			lunch->funeral = true;
			return (NULL);
		}
		ft_usleep(1);
	}
	return (NULL);
}
