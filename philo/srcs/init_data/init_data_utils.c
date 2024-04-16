/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:51:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/16 14:46:28 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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
	int	j;

	j = 0;
	table->philosophers[i].id = i;
	table->philosophers[i].last_meal = -1;
	table->philosophers[i].left_fork = &table->forks[i % table->nbr_of_philos];
	if (table->nbr_of_philos != 1)
		table->philosophers[i].right_fork
			= &table->forks[(i + 1) % table->nbr_of_philos];
	table->philosophers[i].table = table;
	table->philosophers[i].eating = false;
	if (table->max_meals != -1)
		table->philosophers[i].meals_remaining = table->max_meals;
	else
		table->philosophers[i].meals_remaining = -1;
	table->philosophers[i].thread_id = malloc(sizeof(pthread_t));
	if (table->philosophers[i].thread_id == NULL)
	{
		while (j < i)
			free(table->philosophers[j++].thread_id);
		destroy_all_mutexes(table);
		free(table->philosophers);
		return (1);
	}
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
		destroy_all_mutexes(table);
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

static int	set_fork(t_table *table, int i)
{
	int	j;

	j = 0;
	if (pthread_mutex_init(&table->forks[i], NULL) != 0)
	{
		while (j < i)
			pthread_mutex_destroy(&table->forks[j++]);
		free (table->forks);
		write (STDERR_FILENO, "Mutex initialisation error\n", 28);
		return (1);
	}
	return (0);
}

int	set_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
	if (!table->forks)
	{
		write (STDERR_FILENO, "Memory allocation failure\n", 27);
		return (1);
	}
	while (i < table->nbr_of_philos)
	{
		if (set_fork(table, i) != 0)
			return (1);
		i++;
	}
	return (0);
}
