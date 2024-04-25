/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:14:47 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/25 10:47:13 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	solo_philo(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, FORK);
	while (get_bool(table, &table->dinning))
	{
	}
	pthread_mutex_unlock(philo->left_fork);
}

static void	take_or_release_forks(t_philo *philo, int code)
{
	if (code == 0)
	{
		if (philo->id % 2 != 0)
		{
			pthread_mutex_lock(philo->left_fork);
			print_message(philo, FORK);
			pthread_mutex_lock(philo->right_fork);
			print_message(philo, FORK);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			print_message(philo, FORK);
			pthread_mutex_lock(philo->left_fork);
			print_message(philo, FORK);
		}
	}
	else if (code == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	eating(t_table *table, t_philo *philo)
{
	if (table->nbr_of_philos == 1)
	{
		solo_philo(table, philo);
		return ;
	}
	take_or_release_forks(philo, 0);
	set_long(table, &philo->last_meal, get_elapsed_time(table));
	if (philo->last_meal == -1)
		return ;
	print_message(philo, EAT);
	precise_usleep(table, table->time_to_eat * 1000);
	take_or_release_forks(philo, 1);
	if (table->max_meals != -1)
		decrement_int(table, &philo->meals_remaining);
}
