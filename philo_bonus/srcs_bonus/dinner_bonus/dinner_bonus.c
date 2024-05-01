/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:35:04 by imehdid           #+#    #+#             */
/*   Updated: 2024/05/01 22:04:59 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

void	*dinner(void *arg)
{
	t_philo		*philosopher;
	t_table		*table;
	pthread_t	monitor_thread;

	philosopher = (t_philo *)arg;
	table = philosopher->table;
	if (pthread_create(&monitor_thread, NULL, &monitor, philosopher) != 0)
	{
		write (STDERR_FILENO, "Error while creating monitor's thread\n", 39);
		sem_post(table->end);
		usleep(1000);
	}
	if (pthread_detach(monitor_thread) != 0)
	{
		write (STDERR_FILENO, "Error while creating monitor's thread\n", 39);
		sem_post(table->end);
		usleep(1000);
	}
	while (1)
	{
		eating(table, philosopher);
		if (table->max_meals != -1 && philosopher->meals_remaining == 0)
		{
			usleep(100);
			break ;
		}
		sleeping(table, philosopher);
		thinking(table, philosopher);
	}
	return (NULL);
}

static void	terminate_all_processes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		kill(table->philosophers[i].pid, SIGKILL);
		i++;
	}
}

int	start_processes(t_table *table)
{
	int	i;

	i = 0;
	sem_wait(table->end);
	while (i < table->nbr_of_philos)
	{
		table->philosophers[i].pid = fork();
		if (table->philosophers[i].pid < 0)
		{
			write (STDERR_FILENO, "Forking failed\n", 16);
			return (1);
		}
		else if (table->philosophers[i].pid == 0)
			dinner(&table->philosophers[i]);
		i++;
	}
	sem_wait(table->end);
	terminate_all_processes(table);
	return (0);
}

int	start_dinner(t_table *table)
{
	if (gettimeofday(&table->started_time, NULL) != 0)
	{
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (1);
	}
	start_processes(table);
	return (0);
}
