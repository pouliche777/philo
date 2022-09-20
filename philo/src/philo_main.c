/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:55:59 by slord             #+#    #+#             */
/*   Updated: 2022/09/17 19:31:18 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	if (argc > 7)
		return (0);
	table.nb_philo = atoi(argv[1]);
	table.time_to_eat = atoll(argv[3]);
	table.time_without_meal = atoll(argv[2]);
	table.time_to_sleep = atoi(argv[4]);
	table.nb_of_meals = atoi(argv[5]);
	table.meals = 0;
	table.start_time = 0;
	init_mutex(&table);
	if (init_philo(&table) == 0)
		return (0);
	i = 0;
	while (i < table.nb_philo)
	{
		if (pthread_join(table.threads_philo[i], NULL) != 0)
		{
			printf("Can't join threads!");
			return (2);
		}
		i++;
	}
	return (0);
}
