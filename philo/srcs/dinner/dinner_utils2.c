/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:39:32 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/13 18:29:38 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	check_all_philos_meals_remaining(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (table->philosophers[i].meals_remaining != 0)
			return (1);
		i++;
	}
	table->dinning = false;
	return (1);
}

void	*check_all_philos_status(t_table *table)
{
	int		i;
	long	elapsed_time;

	i = 0;
	elapsed_time = 0;
	while (table->dinning)
	{
		if (table->max_meals != -1 && check_all_philos_meals_remaining(table) == 1)
			return (NULL);
		elapsed_time = get_elapsed_time(table);
		if (elapsed_time == -1)
		{
			table->dinning = false;
			write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
			return (NULL);
		}
		if (elapsed_time - table->philosophers[i].last_meal >= table->time_to_die)
		{
			print_message(&table->philosophers[i], DIE);
			table->dinning = false;
			return (NULL);
		}
		i++;
		i = i % table->number_of_philosophers;
	}
	return (NULL);
}