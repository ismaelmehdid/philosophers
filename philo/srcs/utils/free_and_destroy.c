/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:29:59 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/15 20:54:38 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	destroy_and_free_everything(t_table *table)
{
	destroy_all_mutexes(table);
	free_all_threads_slots(table);
	free(table->philosophers);
}

void	free_all_threads_slots(t_table *table)
{
	int	i;

	i = 0;
	if (table->monitor != NULL)
		free(table->monitor);
	while (i < table->nbr_of_philos)
	{
		free(table->philosophers[i].thread_id);
		i++;
	}
}

void	destroy_all_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free (table->forks);
}
