/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:35:04 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/13 17:39:48 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	printf("I am the monitor\n");
	while (get_int(
		table,
		table->number_of_philosophers_ready) != table->number_of_philosophers)
	{
		usleep(1000);//TODO: loop leading to deadlock
	}
	check_all_philos_status(table);
	return (NULL);
}

void	*dinner(void *arg)
{
	t_philo	*philosopher;
	t_table	*table;

	philosopher = (t_philo *)arg;
	table = philosopher->table;
	wait_all_philosophers_to_start(table);
	while (table->dinning)
	{
		thinking(table, philosopher);
		if (table->dinning)
			eating(table, philosopher);
		if (table->max_meals != -1 && philosopher->meals_remaining == 0)
			return (NULL);
		if (table->dinning)
			sleeping(table, philosopher);
	}
	return (NULL);
}

int	start_dinner(t_table *table)
{
	if (philosophers_threads_init(table) != 0)
		return (1);
	if (philosophers_threads_joiner(table) != 0)
		return (1);
	return (0);
}