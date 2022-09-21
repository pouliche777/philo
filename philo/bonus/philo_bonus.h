/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:25:46 by slord             #+#    #+#             */
/*   Updated: 2022/09/20 20:20:07 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				nb_philo;
	sem_t			semaphore;
	pthread_t		*threads_philo;
	time_t			time_to_eat;
	pthread_mutex_t	waiter;
	time_t			time_without_meal;
	time_t			time_to_sleep;
	int				nb_of_meals;
	int				meals;
	time_t			start_time;
	t_philo			*philo;
}	t_table;

typedef struct s_philo
{
	int				n_philo;
	t_table			*table;
	int				meals;
	time_t			time_last_meal;
	pthread_t		thread;
}	t_philo;

void	take_fork(int pos, t_philo philo);
int		init_mutex(t_table *table);
int		init_philo(t_table *table, t_philo *philo);
void	*routine_philo(void *arg);
void	*who_die(void *arg);
void	start(t_philo *philo);
void	eating(t_philo *philo, int pos1, int pos2);
void	sleeping(t_philo philo);
void	thinking(t_philo *philo);
int		death_watcher(t_philo *philo);
time_t	get_time(void);
void	goodnight_sweetprince(t_philo philo, time_t time_to_sleep);
int		free_table(t_table *table);
void	*routine(void *arg);


int init_semaphore(t_table *table);
#endif