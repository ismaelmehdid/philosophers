/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:14:47 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/13 17:06:10 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	eating(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, FORK);
	philo->eating = true;
	philo->last_meal = get_elapsed_time(table);
	if (philo->last_meal == -1)
	{
		table->dinning = false;
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return ;
	}
	wait_and_check(table, philo, EAT);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->eating = false;
	(philo->meals_remaining)--;
}