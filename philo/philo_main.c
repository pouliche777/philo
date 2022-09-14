/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:55:59 by slord             #+#    #+#             */
/*   Updated: 2022/09/13 21:55:58 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char **argv)
{
	t_table	table;
	int		i;
	
	table.nb_philo = atoi(argv[1]);
	table.compteur = 0;
	i = 0;
	table.forks= calloc(sizeof(int), table.nb_philo);
	table.time_to_eat = 3;
	table.time_without_meal = 60000;
	init_mutex(&table);
	init_philo(&table);
	while (i < table.nb_philo)
	{
		if (pthread_join(table.threads_philo[i], NULL) != 0)
		{
			printf("Erreur, impossible de joindre");
			return (2);
		}
		i++;
	}
}
