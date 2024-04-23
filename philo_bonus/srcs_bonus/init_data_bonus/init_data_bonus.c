/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:45:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/20 17:32:25 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

static int	set_table_data_utils(int argc, char **argv, t_table *table)
{
	table->nbr_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->nbr_of_philos_ready = 0;
	table->monitor_ready = false;
	table->dinning = true;
	if (argc == 6)
		table->max_meals = ft_atoi(argv[5]);
	else
		table->max_meals = -1;
	table->forks = sem_open("/forks", O_CREAT, 0644, table->nbr_of_philos);
	if (table->forks == SEM_FAILED)
	{
		write (STDERR_FILENO, "Semaphore opening error\n", 25);
		if (sem_close(table->data_semaphore) == -1)
			write (STDERR_FILENO, "Error while closing a semaphore\n", 33);
		if (sem_unlink("/data_semaphore"))
			write (STDERR_FILENO, "Error while unlinking a semaphore\n", 35);
		return (1);
	}
	return (0);
}

static int	set_table_data(int argc, char **argv, t_table *table)
{
	table->data_semaphore = sem_open("/data_semaphore", O_CREAT, 0644, 1);
	if (table->data_semaphore == SEM_FAILED)
	{
		write (STDERR_FILENO, "Semaphore opening error\n", 25);
		return (1);
	}
	if (set_table_data_utils(argc, argv, table) != 0)
		return (1);
	if (set_monitor(table) != 0)
		return (1);
	if (set_philosophers(table) != 0)
		return (1);
	return (0);
}

int	init_data(int argc, char **argv, t_table *table)
{
	if (errors_handling(argc, argv) != 0)
		return (1);
	if (set_table_data(argc, argv, table) != 0)
		return (1);
	return (0);
}
