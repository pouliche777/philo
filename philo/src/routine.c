/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:42:46 by slord             #+#    #+#             */
/*   Updated: 2022/09/20 18:42:56 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{	
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->n_philo % 2 == 0)
		usleep(10000);
	philo->meals = 0;
	start(philo);
	return (0);
}
