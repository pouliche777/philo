/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:21:00 by slord             #+#    #+#             */
/*   Updated: 2022/09/13 22:05:59 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int mails;
void	init_mutex(t_table *table)
{
	pthread_mutex_init(&table->mutex, NULL);
}

void	init_philo(t_table *table)
{
	int			i;
	t_philo		*philo;
	pthread_t	waiter;

	table->threads_philo = malloc(sizeof(pthread_t) * table->nb_philo);
	philo = malloc(sizeof(t_philo) * table->nb_philo);
	i = 0;
	while (i < table->nb_philo)
	{
		philo[i].n_philo = i;
		philo[i].table = table;
		i++;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->threads_philo[i],NULL, &routine_philo, &philo[i]) != 0)
			exit(1);
		i++;
	}
	
	//if (pthread_create(&waiter, NULL, &who_die, philo) != 0)
		//	exit(1);

}
