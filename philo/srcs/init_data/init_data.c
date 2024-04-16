/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:45:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/16 14:30:31 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	set_table_data_utils(int argc, char **argv, t_table *table)
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
}

static int	set_table_data(int argc, char **argv, t_table *table)
{
	if (gettimeofday(&table->started_time, NULL) != 0)
	{
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (1);
	}
	if (pthread_mutex_init(&table->data_mutex, NULL) != 0)
	{
		write (STDERR_FILENO, "Mutex initialisation error\n", 28);
		return (1);
	}
	set_table_data_utils(argc, argv, table);
	if (set_forks(table) != 0)
		return (1);
	if (set_philosophers(table) != 0)
		return (1);
	if (set_monitor(table) != 0)
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
