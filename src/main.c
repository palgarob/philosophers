/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:30:30 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/08 14:25:31 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_lunch	lunch;

	if (parse_args(argc, argv, &lunch))
		return (1);
	if (init_lunch(&lunch))
		return (2);
	if (philo(&lunch))
		return (3);
	return (0);
}
