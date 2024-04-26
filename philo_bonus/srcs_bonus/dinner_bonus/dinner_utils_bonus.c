/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:40:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/26 19:07:30 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

void	precise_usleep(long microsec)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed;

	elapsed = 0;
	if (gettimeofday(&start, NULL) != 0)
	{
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		exit (SYSTEM_ERROR);
	}
	while (1)
	{
		if (gettimeofday(&current, NULL) != 0)
		{
			write (STDERR_FILENO, "Error while getting the time of the day\n",
				41);
			exit (SYSTEM_ERROR);
		}
		elapsed = (current.tv_sec - start.tv_sec) * 1000000
			+ (current.tv_usec - start.tv_usec);
		if (elapsed >= microsec)
			break ;
	}
}

long	get_elapsed_time(t_table *table, t_types type)
{
	struct timeval	actual_time;

	if (gettimeofday(&actual_time, NULL) != 0)
	{
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		if (type == EAT)
		{
			sem_post(table->forks);
			sem_post(table->forks);
		}
		exit (SYSTEM_ERROR);
	}
	return ((actual_time.tv_sec - table->started_time.tv_sec) * 1000
		+ (actual_time.tv_usec - table->started_time.tv_usec) / 1000);
}

void	print_message(t_philo *philo, t_types code)
{
	sem_wait(philo->table->data_semaphore);
	if (code == EAT)
		printf(
			"%ld %d is \033[32meating\033[0m\n",
			get_elapsed_time(philo->table, NONE), philo->id);
	else if (code == SLEEP)
		printf(
			"%ld %d is \033[34msleeping\033[0m\n",
			get_elapsed_time(philo->table, NONE), philo->id);
	else if (code == THINK)
		printf(
			"%ld %d is \033[33mthinking\033[0m\n",
			get_elapsed_time(philo->table, NONE), philo->id);
	else if (code == FORK)
		printf(
			"%ld %d has \033[32mtaken a fork\033[0m\n",
			get_elapsed_time(philo->table, NONE), philo->id);
	else if (code == DIE)
		printf(
			"%ld %d \033[91mdied\033[0m\n",
			get_elapsed_time(philo->table, NONE), philo->id);
	sem_post(philo->table->data_semaphore);
}
