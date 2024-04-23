/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:14:47 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/22 14:40:03 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

void	eating(t_table *table, t_philo *philo)
{
	sem_wait(table->forks);
	sem_wait(table->forks);
	philo->eating = true;
	philo->last_meal = get_elapsed_time(table);
	if (philo->last_meal == -1)
		return ;
	print_message(philo, EAT);
	precise_usleep(table, table->time_to_eat * 1000);
	sem_post(table->forks);
	sem_post(table->forks);
	philo->eating = false;
	if (table->max_meals != -1)
		(philo->meals_remaining)--;
}
