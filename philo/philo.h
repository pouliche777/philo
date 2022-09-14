/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:25:46 by slord             #+#    #+#             */
/*   Updated: 2022/09/13 20:46:28 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>



typedef struct s_table
{
	int				nb_philo;
	int				die;
	pthread_mutex_t	mutex;
	pthread_t		*threads_philo;
	int				compteur;
	int 			*forks;
	int 			time_to_eat;
	time_t			time_without_meal;
}	t_table;

typedef struct s_philo
{
	int				n_philo;
	t_table			*table;
	int				meals;
	pthread_mutex_t	mutex;
	time_t			time_last_meal;
}	t_philo;

void	init_mutex(t_table *table);
void	init_philo(t_table *table);
void	*routine_philo(void *arg);
void	*who_die(void *arg);
void	*eats(t_philo *philo);
time_t	get_time(void);
#endif