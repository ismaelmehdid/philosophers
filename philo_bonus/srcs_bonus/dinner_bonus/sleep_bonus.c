/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:14:55 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/18 20:28:01 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

void	sleeping(t_table *table, t_philo *philo)
{
	if (table->dinning)
		print_message(philo, SLEEP);
	else
		return ;
	precise_usleep(table, table->time_to_sleep * 1000);
}
