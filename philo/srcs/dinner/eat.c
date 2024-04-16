/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:14:47 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/16 20:06:18 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	eat_loop(t_table *table, t_philo *philo)
{
	long	time_to_finish;
	long	elapsed_time;

	elapsed_time = get_elapsed_time(table);
	if (elapsed_time == -1)
		return ;
	time_to_finish = elapsed_time + table->time_to_eat;
	print_message(philo, EAT);
	while (table->dinning == true && elapsed_time < time_to_finish)
	{
		elapsed_time = get_elapsed_time(table);
		if (elapsed_time == -1)
			return ;
	}
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
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, FORK);
	}
	else
		take_or_release_forks(philo, 0);
	philo->eating = true;
	philo->last_meal = get_elapsed_time(table);
	if (philo->last_meal == -1)
		return ;
	eat_loop(table, philo);
	if (table->nbr_of_philos == 1)
		pthread_mutex_unlock(philo->left_fork);
	else
		take_or_release_forks(philo, 1);
	philo->eating = false;
	if (table->max_meals != -1)
		(philo->meals_remaining)--;
}