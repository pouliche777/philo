/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:21:00 by slord             #+#    #+#             */
/*   Updated: 2022/09/20 15:53:49 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_table *table)
{
	int	i;
	
	i = 0;
	table->mutex = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&table->mutex[i], NULL);
		i++;
	}
	if (pthread_mutex_init(&table->waiter, NULL) != 0)
		return (1);
	return (0);
}

int	init_philo(t_table *table)
{
	int			i;
	t_philo		*philo;

	table->threads_philo = malloc(sizeof(pthread_t) * table->nb_philo);
	philo = malloc(sizeof(t_philo) * table->nb_philo);
	i = 0;
	while (i < table->nb_philo)
	{
		philo[i].n_philo = i;
		philo[i].table = table;
		philo[i].time_last_meal = 0;
		philo[i].thread = table->threads_philo[i];
		i++;
	}
	i = 0;
	table->start_time = get_time();
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->threads_philo[i],NULL, &routine_philo, &philo[i]) != 0)
			return(0);
		i++;
	}
	if (!death_watcher(philo))
		return (0);
	return (1);
}
