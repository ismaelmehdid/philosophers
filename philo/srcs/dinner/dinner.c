/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <imehdid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:35:04 by imehdid           #+#    #+#             */
/*   Updated: 2024/05/02 13:58:58 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*dinner(void *arg)
{
	t_philo	*philosopher;
	t_table	*table;

	philosopher = (t_philo *)arg;
	table = philosopher->table;
	if (DEBUG == 0)
		synchronize_every_threads(table);
	while (get_bool(table, &table->dinning))
	{
		eating(table, philosopher);
		if (table->max_meals != -1
			&& get_int(table, &philosopher->meals_remaining) == 0)
		{
			return (NULL);
		}
		sleeping(table, philosopher);
		thinking(table, philosopher);
	}
	return (NULL);
}

int	start_dinner(t_table *table)
{
	if (DEBUG == 1 && gettimeofday(&table->started_time, NULL) != 0)
	{
		set_bool(table, &table->dinning, false);
		destroy_and_free_everything(table);
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return (1);
	}
	if (philosophers_threads_init(table) != 0)
	{
		return (1);
	}
	if (philosophers_threads_joiner(table) != 0)
	{
		return (1);
	}
	return (0);
}
