/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:19:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/18 18:45:57 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	check_meals_remaining(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		if (table->philosophers[i].meals_remaining != 0)
			return (0);
		i++;
	}
	table->dinning = false;
	return (1);
}

static void	*check_all_philos_status(t_table *table)
{
	int		i;
	long	elapsed_time;

	i = 0;
	elapsed_time = 0;
	while (table->dinning)
	{
		if (table->max_meals != -1 && check_meals_remaining(table) == 1)
			return (NULL);
		elapsed_time = get_elapsed_time(table);
		if (elapsed_time == -1)
			return (NULL);
		if (table->philosophers[i].meals_remaining != 0
			&& ((elapsed_time - table->philosophers[i].last_meal)
				>= table->time_to_die))
		{
			print_message(&table->philosophers[i], DIE);
			table->dinning = false;
			return (NULL);
		}
		i++;
		i = i % table->nbr_of_philos;
	}
	return (NULL);
}

static int	wait_and_set_starting_time(t_table *table)
{
	while (table->nbr_of_philos_ready != table->nbr_of_philos)
	{
	}
	if (gettimeofday(&table->started_time, NULL) != 0)
	{
		table->dinning = false;
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (1);
	}
	table->monitor_ready = true;
	return (0);
}

void	*monitor(void *arg)
{
	t_table			*table;

	table = (t_table *)arg;
	printf("I am the monitor\n");
	if (wait_and_set_starting_time(table) != 0)
		return (NULL);
	check_all_philos_status(table);
	return (NULL);
}
