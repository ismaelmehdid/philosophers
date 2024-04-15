/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:43:08 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/15 20:58:30 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	philosophers_threads_init(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_create(table->monitor, NULL, &monitor, table) != 0)
	{
		write (STDERR_FILENO, "Error while creating monitor's thread\n", 39);
		destroy_and_free_everything(table);
		return (1);
	}
	while (i < table->nbr_of_philos)
	{
		if (pthread_create(table->philosophers[i].thread_id, NULL, &dinner,
				&table->philosophers[i]) != 0)
		{
			write (STDERR_FILENO, "Error while creating threads\n", 30);
			destroy_and_free_everything(table);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philosophers_threads_joiner(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_join(*table->monitor, NULL) != 0)
	{
		write (STDERR_FILENO, "Error while joining monitor's thread\n", 38);
		destroy_and_free_everything(table);
		return (1);
	}
	while (i < table->nbr_of_philos)
	{
		if (pthread_join(*table->philosophers[i].thread_id, NULL) != 0)
		{
			write (STDERR_FILENO, "Error while joining threads\n", 29);
			destroy_and_free_everything(table);
			return (1);
		}
		i++;
	}
	return (0);
}
