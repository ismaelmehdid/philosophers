/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:35:04 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/18 18:34:49 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*dinner(void *arg)
{
	t_philo	*philosopher;
	t_table	*table;

	philosopher = (t_philo *)arg;
	table = philosopher->table;
	synchronize_every_threads(table);
	while (table->dinning)
	{
		eating(table, philosopher);
		if (table->max_meals != -1 && philosopher->meals_remaining == 0)
			return (NULL);
		sleeping(table, philosopher);
		thinking(table, philosopher);
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
