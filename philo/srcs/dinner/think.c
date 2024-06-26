/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:33:16 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/24 23:46:25 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	thinking(t_table *table, t_philo *philo)
{
	long	thinking_time;

	if (get_bool(table, &table->dinning))
		print_message(philo, THINK);
	if (table->nbr_of_philos % 2 != 0)
	{
		thinking_time = (table->time_to_eat * 2) - table->time_to_sleep;
		if (thinking_time < 0)
			thinking_time = 0;
		precise_usleep(table, thinking_time * 1000);
	}
}
