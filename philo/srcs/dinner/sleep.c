/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:14:55 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/15 20:23:14 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	sleeping(t_table *table, t_philo *philo)
{
	long	time_to_finish;
	long	elapsed_time;

	elapsed_time = get_elapsed_time(table);
	if (elapsed_time == -1)
		return ;
	time_to_finish = elapsed_time + table->time_to_sleep;
	print_message(philo, SLEEP);
	while (table->dinning == true && elapsed_time < time_to_finish)
	{
		elapsed_time = get_elapsed_time(table);
		if (elapsed_time == -1)
			return ;
	}
}
