/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:42:46 by slord             #+#    #+#             */
/*   Updated: 2022/09/13 22:01:01 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*who_die(void *arg)
{
	t_philo	*philo;
	int		i;
	
	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		while(i < philo[i].table->nb_philo)
		{
			if ((get_time() - philo[i].time_last_meal) >= philo[i].table->time_without_meal)
			{
				printf("philosopher %d has died\n", philo[i].n_philo);
				exit(1);
			}
			i++;
			if (i == philo[i].table->nb_philo)
				i = 0;
		}
	}
}

void	*routine_philo(void *arg)
{	
	t_philo	philo;
	pthread_t tid;

	philo = *(t_philo *)arg;
	philo.meals = 0;
	/*pthread_mutex_lock(&philo.table->mutex);
	printf("philosphe_%d existe!\n", philo.n_philo);
	tid = pthread_self();
	printf("%ld\n", tid);
	pthread_mutex_unlock(&philo.table->mutex); */
	eats(&philo);
	return (0);
}

