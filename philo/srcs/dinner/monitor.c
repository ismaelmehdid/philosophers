/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <imehdid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:19:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/05/02 14:10:34 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	check_meals_remaining(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		if (get_int(table, &table->philosophers[i].meals_remaining) != 0)
			return (0);
		i++;
	}
	set_bool(table, &table->dinning, false);
	return (1);
}

static int	check_philo_death(t_table *table, int i, long elapsed_time)
{
	if (get_int(table, &table->philosophers[i].meals_remaining) != 0
		&& ((elapsed_time
				- get_long(table, &table->philosophers[i].last_meal))
			>= table->time_to_die))
	{
		print_message(&table->philosophers[i], DIE);
		set_bool(table, &table->dinning, false);
		pthread_mutex_unlock(&table->message_mutex);
		return (1);
	}
	return (0);
}

static void	*check_all_philos_status(t_table *table)
{
	int		i;
	long	elapsed_time;

	i = 0;
	elapsed_time = 0;
	while (get_bool(table, &table->dinning))
	{
		if (table->max_meals != -1 && check_meals_remaining(table) == 1)
			return (NULL);
		elapsed_time = get_elapsed_time(table);
		if (elapsed_time == -1)
			return (NULL);
		if (check_philo_death(table, i, elapsed_time) != 0)
			return (NULL);
		i++;
		i = i % table->nbr_of_philos;
		if (DEBUG == 1)
			usleep(1000);
	}
	return (NULL);
}

static int	wait_and_set_starting_time(t_table *table)
{
	while (get_int(table, &table->nbr_of_philos_ready) != table->nbr_of_philos)
	{
	}
	if (gettimeofday(&table->started_time, NULL) != 0)
	{
		set_bool(table, &table->dinning, false);
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (1);
	}
	set_bool(table, &table->monitor_ready, true);
	return (0);
}

void	*monitor(void *arg)
{
	t_table			*table;

	table = (t_table *)arg;
	if (DEBUG == 0 && wait_and_set_starting_time(table) != 0)
		return (NULL);
	check_all_philos_status(table);
	return (NULL);
}
