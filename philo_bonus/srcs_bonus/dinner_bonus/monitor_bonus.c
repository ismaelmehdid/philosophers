/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:19:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/05/01 22:42:17 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

static void	*check_philo_status(t_philo *philo)
{
	long	elapsed_time;

	elapsed_time = 0;
	while (1)
	{
		if (philo->table->max_meals != -1 && philo->meals_remaining == 0)
		{
			sem_post(philo->table->end);
			break ;
		}
		elapsed_time = get_elapsed_time(philo->table, NONE);
		if (((elapsed_time - get_long(philo->table, &philo->last_meal))
				>= philo->table->time_to_die))
		{
			if (philo->table->nbr_of_philos == 1)
				sem_post(philo->table->forks);
			printf("%ld %d \033[91mdied\033[0m\n",
				get_elapsed_time(philo->table, NONE), philo->id);
			sem_post(philo->table->end);
			break ;
		}
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	check_philo_status(philosopher);
	return (NULL);
}
