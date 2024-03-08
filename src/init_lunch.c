/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lunch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:48:42 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/06 18:54:47 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mallocs(t_lunch *lunch)
{
	lunch->threads = (pthread_t *)malloc(sizeof(pthread_t) * lunch->n_philos);
	if (!lunch->threads)
	{
		printf(ERROR_MALLOC);
		return (1);
	}
	lunch->philos = (t_philo *)malloc(sizeof(t_philo) * lunch->n_philos);
	if (!lunch->philos)
	{
		printf(ERROR_MALLOC);
		free(lunch->threads);
		return (2);
	}
	lunch->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * lunch->n_philos);
	if (!lunch->forks)
	{
		printf(ERROR_MALLOC);
		free_mallocs(lunch);
		return(3);
	}
	return (0);
}

static void	init_philos(t_lunch *lunch)
{
	int	i;

	i = -1;
	while (++i < lunch->n_philos)
	{
		lunch->philos[i].lunch = lunch;
		lunch->philos[i].id = i + 1;
		lunch->philos[i].n_meals_had = 0;
		//pthread_mutex_init(&lunch->philos[i].mut_last_ate, NULL);
		//pthread_mutex_init(&lunch->philos[i].mut_meals_had, NULL);
	}
}

static int	init_forks(t_lunch *lunch)
{
	int	i;

	i = -1;
	while (++i < lunch->n_philos)
	{
		if (pthread_mutex_init(&lunch->forks[i], NULL))
		{
			printf(ERROR_MUTEX_INIT);
			return (1);
		}
	}
	i = 0;
	lunch->philos[i].l_fork = &lunch->forks[i];
	lunch->philos[i].r_fork = &lunch->forks[lunch->n_philos - 1];
	while (++i < lunch->n_philos)
	{
		lunch->philos[i].l_fork = &lunch->forks[i];
		lunch->philos[i].r_fork = &lunch->forks[i - 1];
	}
	return (0);
}

int	init_lunch(t_lunch *lunch)
{
	lunch->funeral = 0;
	if (pthread_mutex_init(&lunch->mut_funeral, NULL))
	{
		printf(ERROR_MUTEX_INIT);
		return (3);
	}
	if (init_mallocs(lunch))
		return (1);
	init_philos(lunch);
	if (init_forks(lunch))
	{
		free_mallocs(lunch);
		return (2);
	}
	return (0);
}
