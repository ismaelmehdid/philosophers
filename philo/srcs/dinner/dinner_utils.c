/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:40:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/16 20:16:30 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long	get_elapsed_time(t_table *table)
{
	struct timeval	actual_time;

	if (gettimeofday(&actual_time, NULL) != 0)
	{
		table->dinning = false;
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (-1);
	}
	return ((actual_time.tv_sec - table->started_time.tv_sec) * 1000
		+ (actual_time.tv_usec - table->started_time.tv_usec) / 1000);
}

void	synchronize_every_threads(t_table *table)
{
	increment_int(table, &table->nbr_of_philos_ready);
	while ((table->nbr_of_philos_ready != table->nbr_of_philos
			|| table->monitor_ready == false) && table->dinning == true)
	{
	}
}

void	print_message(t_philo *philo, t_types code)
{
	pthread_mutex_lock(&philo->table->data_mutex);
	if (code == EAT && philo->table->dinning)
		printf(
			"%ld %d is \033[32meating\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == SLEEP && philo->table->dinning)
		printf(
			"%ld %d is \033[34msleeping\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == THINK && philo->table->dinning)
		printf(
			"%ld %d is \033[33mthinking\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == FORK && philo->table->dinning)
		printf(
			"%ld %d has \033[32mtaken a fork\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == DIE && philo->table->dinning)
		printf(
			"%ld %d \033[91mdied\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->data_mutex);
}
