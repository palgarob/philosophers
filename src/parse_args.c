/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:25:17 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/09 21:09:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	n;

	n = 0;
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

static int	check_args(char **argv)
{
	char	*aux;

	while (*argv)
	{
		aux = *argv;
		while (*aux)
		{
			if (*aux < '0' || *aux > '9')
				return (1);
			aux++;
		}
		argv++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_lunch *lunch)
{
	if (argc < 5 || argc > 6)
		return (printf(ERROR_ARGNUM), 1);
	if (check_args(argv + 1))
		return (printf(ERROR_ONLY_NUM), 1);
	lunch->n_philos = ft_atoi(argv[1]);
	lunch->t_die = (unsigned long)ft_atoi(argv[2]);
	lunch->t_eat = (unsigned long)ft_atoi(argv[3]);
	lunch->t_sleep = (unsigned long)ft_atoi(argv[4]);
	lunch->must_eat = -1;
	if (argv[5])
		lunch->must_eat = ft_atoi(argv[5]);
	if (!lunch->must_eat || !lunch->n_philos)
		return (printf(ERROR_VALUES), 1);
	return (0);
}
