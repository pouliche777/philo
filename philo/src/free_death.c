/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:01:33 by slord             #+#    #+#             */
/*   Updated: 2022/09/20 15:18:44 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_watcher(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo[i].table->meals == philo[i].table->nb_of_meals * philo[i].table->nb_philo)
			return (0);
		if ((get_time() - philo[i].table->start_time - philo[i].time_last_meal) >= philo[i].table->time_without_meal)
		{
			if (philo[i].meals != philo->table->nb_of_meals)
			{
				pthread_mutex_lock(&philo->table->waiter);
				printf(" %lu philosopher %d has died\n",get_time() - philo[i].table->start_time, philo[i].n_philo + 1);
				exit (0);
			}
		}
		i++;
		if (i == philo->table->nb_philo)
			i = 0;
	}
	return (1);
}
