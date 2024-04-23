/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:19:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/20 17:51:16 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

static void	*check_philo_status(t_philo *philo)
{
	long	elapsed_time;

	elapsed_time = 0;
	while (1)
	{
		if (philo->meals_remaining != -1 && philo->meals_remaining == 0)
			exit(0);
		elapsed_time = get_elapsed_time(philo->table);
		if (elapsed_time == -1)
			exit (2);
		if (((elapsed_time - philo->last_meal) >= philo->table->time_to_die))
		{
			print_message(philo, DIE);
			exit(EXIT_SUCCESS);
		}
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	printf("I am the monitor\n");
	check_philo_status(philosopher);
	return (NULL);
}
