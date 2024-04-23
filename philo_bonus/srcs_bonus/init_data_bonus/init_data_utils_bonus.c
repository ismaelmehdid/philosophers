/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:51:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/19 22:06:03 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

int	set_monitor(t_table *table)
{
	table->monitor = malloc(sizeof(pthread_t));
	if (!table->monitor)
	{
		write (STDERR_FILENO, "Memory allocation failure\n", 27);
		destroy_and_free_everything(table);
		return (1);
	}
	return (0);
}

static int	set_philosopher(t_table *table, int i)
{
	table->philosophers[i].id = i;
	table->philosophers[i].last_meal = -1;
	table->philosophers[i].table = table;
	table->philosophers[i].eating = false;
	if (table->max_meals != -1)
		table->philosophers[i].meals_remaining = table->max_meals;
	else
		table->philosophers[i].meals_remaining = -1;
	return (0);
}

int	set_philosophers(t_table *table)
{
	int	i;

	i = 0;
	table->philosophers = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if (!table->philosophers)
	{
		write (STDERR_FILENO, "Memory allocation failure\n", 27);
		destroy_all_semaphores(table);
		return (1);
	}
	while (i < table->nbr_of_philos)
	{
		if (set_philosopher(table, i) != 0)
			return (1);
		i++;
	}
	return (0);
}
