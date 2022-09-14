/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:32:15 by slord             #+#    #+#             */
/*   Updated: 2022/09/13 21:44:35 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eats(t_philo *philo)
{
	int	pos;
	int	pos_d;
	int	pos_g;

	pos = philo->n_philo;
	pos_g = pos;
	pos_d = pos + 1;

	if (pos_d == philo->table->nb_philo)
		pos_d = 0;
	while (philo->meals != philo->table->time_to_eat)
	{
		pthread_mutex_lock(&philo->table->mutex);
		if (philo->table->forks[pos_g] == 0 && philo->table->forks[pos_d] == 0)
		{
			philo->table->forks[pos_g] = 1;
			philo->table->forks[pos_d] = 1;
			printf("philosopher %d has taken a fork\n", pos);
			printf("philosopher %d has taken a fork\n", pos);
			printf("philosopher %d is eating\n", pos);
			pthread_mutex_unlock(&philo->table->mutex);
			//time to eat
			
			usleep (5000);
			pthread_mutex_lock(&philo->table->mutex);
			philo->table->forks[pos_g] = 0;
			philo->table->forks[pos_d] = 0;
			pthread_mutex_unlock(&philo->table->mutex);
			philo->meals++;
			philo->time_last_meal = get_time();
			pthread_mutex_lock(&philo->table->mutex);
			printf("philosopher %d is sleeping\n", pos);
			pthread_mutex_unlock(&philo->table->mutex);
			//time to sleep
			usleep (5000);
			pthread_mutex_lock(&philo->table->mutex);
			printf("philosopher %d is thinking\n", pos);
			pthread_mutex_unlock(&philo->table->mutex);
			//time to think
			usleep (5000);
		}
		pthread_mutex_unlock(&philo->table->mutex);
		
	}
	
}
