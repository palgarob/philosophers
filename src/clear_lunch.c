/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:32 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/09 22:08:46 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mallocs(t_lunch *lunch)
{
	if (lunch->forks)
		free(lunch->forks);
	if (lunch->philos)
		free(lunch->philos);
}

void	clear_lunch(t_lunch *lunch)
{
	int	i;

	i = -1;
	while (++i < lunch->n_philos)
	{
		if (pthread_mutex_destroy(&lunch->forks[i]) || pthread_mutex_destroy(&lunch->philos[i].mut_last_ate))
		{
			printf(ERROR_MUTEX_DEST);
			return ;
		}
	}
	if (pthread_mutex_destroy(&lunch->mut_funeral) || pthread_mutex_destroy(&lunch->mut_notify))
	{
		printf(ERROR_MUTEX_DEST);
		return ;
	}
	free_mallocs(lunch);
}
