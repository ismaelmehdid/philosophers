/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:35:04 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/26 19:10:55 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

void	*dinner(void *arg)
{
	t_philo	*philosopher;
	t_table	*table;

	philosopher = (t_philo *)arg;
	table = philosopher->table;
	if (pthread_create(table->monitor, NULL, &monitor, philosopher) != 0)
	{
		write (STDERR_FILENO, "Error while creating monitor's thread\n", 39);
		exit (SYSTEM_ERROR);
	}
	if (pthread_detach(*table->monitor) != 0)
	{
		write (STDERR_FILENO, "Error while creating monitor's thread\n", 39);
		exit (SYSTEM_ERROR);
	}
	while (1)
	{
		eating(table, philosopher);
		if (table->max_meals != -1 && philosopher->meals_remaining == 0)
			exit (PHILO_FULL);
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

static void	wait_all_processes(t_table *table, int status, int exit_status)
{
	pid_t	pid;

	pid = 0;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid > 0)
		{
			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
				if (exit_status == PHILO_DEATH || exit_status == SYSTEM_ERROR)
				{
					terminate_all_processes(table);
					break ;
				}
			}
		}
		else if (pid == -1)
			break ;
	}
	if (exit_status == PHILO_DEATH)
		sem_post(table->data_semaphore);
}

int	start_processes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		table->philosophers[i].pid = fork();
		if (table->philosophers[i].pid < 0)
		{
			write (STDERR_FILENO, "Forking failed\n", 16);
			return (1);
		}
		else if (table->philosophers[i].pid == 0)
		{
			dinner(&table->philosophers[i]);
		}
		i++;
	}
	wait_all_processes(table, 0, 0);
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
