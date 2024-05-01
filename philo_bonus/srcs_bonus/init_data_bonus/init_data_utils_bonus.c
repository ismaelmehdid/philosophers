/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:51:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/05/01 18:38:21 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

static int	set_philosopher(t_table *table, int i)
{
	table->philosophers[i].id = i;
	table->philosophers[i].last_meal = -1;
	table->philosophers[i].table = table;
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
		free(table->monitor);
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
