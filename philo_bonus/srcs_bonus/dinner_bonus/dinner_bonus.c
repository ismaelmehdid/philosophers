/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:35:04 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/20 17:38:58 by imehdid          ###   ########.fr       */
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
		exit (2);
	}
	if (pthread_detach(*table->monitor) != 0)
	{
		write (STDERR_FILENO, "Error while creating monitor's thread\n", 39);
		exit (2);
	}
	while (1)
	{
		eating(table, philosopher);
		if (table->max_meals != -1 && philosopher->meals_remaining == 0)
			exit (0);
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
		kill(table->philosophers[i].pid, SIGINT);
		i++;
	}
}

static void	wait_all_processes(t_table *table)
{
	pid_t	pid;
	int		status;
	int		exit_status;

	pid = 0;
	status = 0;
	exit_status = 0;
	while (1)
	{
		pid = waitpid(-1, &status, 0); //TODO: protect message with a semaphore so it does not print a message after a death
		if (pid > 0)
		{
			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
				if (exit_status != 0)
				{
					terminate_all_processes(table);
					return ;
				}
			}
		}
		else if (pid == -1)
			return ;
	}
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
	wait_all_processes(table);
	return (0);
}

int	start_dinner(t_table *table)
{
	if (gettimeofday(&table->started_time, NULL) != 0)
	{
		table->dinning = false;
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (1);
	}
	start_processes(table);
	return (0);
}
