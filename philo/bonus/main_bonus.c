/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:10:12 by slord             #+#    #+#             */
/*   Updated: 2022/09/20 20:27:47 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char **argv)
{
	t_philo	*philo;
	t_table	table;
	int i = 0;
	if (argc > 7)
		return (0);
	table.nb_philo = atoi(argv[1]);
	table.time_to_eat = atoll(argv[3]);
	table.time_without_meal = atoll(argv[2]);
	table.time_to_sleep = atoi(argv[4]);
	table.nb_of_meals = atoi(argv[5]);
	table.meals = 0;
	table.start_time = 0;

	sem_init(&table.semaphore, 0, 1);
	philo = malloc(sizeof(t_philo) * table.nb_philo);
	init_philo(&table, philo);
	

	while (i < table.nb_philo)
	{
		if (pthread_join(table.threads_philo[i], NULL) != 0)
		{
			printf("Can't join threads!");
			return (2);
		}
		i++;
	}	
	
}

int	init_philo(t_table *table, t_philo *philo)
{
	int			i;

	table->threads_philo = malloc(sizeof(pthread_t) * table->nb_philo);
	
	i = 0;
	//table->philo = philo;
	while (i < table->nb_philo)
	{
		philo[i].n_philo = i;
		philo[i].table = table;
		philo[i].time_last_meal = 1;
		philo[i].thread = table->threads_philo[i];
		
		i++;
	}
	i = 0;
	
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->threads_philo[i],NULL, &routine, &philo[i]) != 0)
			return(0);
		i++;
	}
	return (1);	
}

int init_semaphore(t_table *table)
{
	sem_init(&table->semaphore, 0, 1);
}
void *routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	sem_wait(&philo->table->semaphore);
	
	printf("poulet de thread %d\n", philo->n_philo);
	sleep(5);
	philo->meals = 0;
	sem_post(&philo->table->semaphore);
	return (0);
}
