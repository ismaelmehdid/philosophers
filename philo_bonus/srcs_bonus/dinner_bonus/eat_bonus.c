/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:14:47 by imehdid           #+#    #+#             */
/*   Updated: 2024/05/01 21:35:12 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

void	eating(t_table *table, t_philo *philo)
{
	if (table->nbr_of_philos != 1)
		sem_wait(table->forks_protection);
	sem_wait(table->forks);
	print_message(philo, FORK);
	sem_wait(table->forks);
	print_message(philo, FORK);
	sem_post(table->forks_protection);
	set_long(table, &philo->last_meal, get_elapsed_time(table, EAT));
	print_message(philo, EAT);
	precise_usleep(table, table->time_to_eat * 1000);
	sem_post(table->forks);
	sem_post(table->forks);
	if (table->max_meals != -1)
		(philo->meals_remaining)--;
}
