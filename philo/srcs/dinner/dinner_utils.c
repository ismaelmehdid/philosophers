/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:40:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/29 19:23:31 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	precise_usleep(t_table *table, long microsec)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed;

	elapsed = 0;
	if (gettimeofday(&start, NULL) != 0)
	{
		set_bool(table, &table->dinning, false);
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return ;
	}
	while (get_bool(table, &table->dinning))
	{
		if (gettimeofday(&current, NULL) != 0)
		{
			set_bool(table, &table->dinning, false);
			write (STDERR_FILENO, "Error while getting the time of the day\n",
				41);
			return ;
		}
		elapsed = (current.tv_sec - start.tv_sec) * 1000000
			+ (current.tv_usec - start.tv_usec);
		if (elapsed >= microsec)
			break ;
	}
}

long	get_elapsed_time(t_table *table)
{
	struct timeval	actual_time;

	if (gettimeofday(&actual_time, NULL) != 0)
	{
		set_bool(table, &table->dinning, false);
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (-1);
	}
	return ((actual_time.tv_sec - table->started_time.tv_sec) * 1000
		+ (actual_time.tv_usec - table->started_time.tv_usec) / 1000);
}

void	synchronize_every_threads(t_table *table)
{
	increment_int(table, &table->nbr_of_philos_ready);
	while ((get_int(table, &table->nbr_of_philos_ready) != table->nbr_of_philos
			|| get_bool(table, &table->monitor_ready) == false)
		&& get_bool(table, &table->dinning) == true)
	{
	}
}

void	print_message(t_philo *philo, t_types code)
{
	if (code == EAT && get_bool(philo->table, &philo->table->dinning))
		printf(
			"%ld %d is \033[32meating\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == SLEEP && get_bool(philo->table, &philo->table->dinning))
		printf(
			"%ld %d is \033[34msleeping\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == THINK && get_bool(philo->table, &philo->table->dinning))
		printf(
			"%ld %d is \033[33mthinking\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == FORK && get_bool(philo->table, &philo->table->dinning))
		printf(
			"%ld %d has \033[32mtaken a fork\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == DIE && get_bool(philo->table, &philo->table->dinning))
		printf(
			"%ld %d \033[91mdied\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
}
