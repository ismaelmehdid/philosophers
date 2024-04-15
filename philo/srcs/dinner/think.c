/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:33:16 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/15 20:59:33 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	thinking(t_table *table, t_philo *philo)
{
	int	right_philo;
	int	left_philo;

	print_message(philo, THINK);
	right_philo
		= ((philo->id - 1 + table->nbr_of_philos) % table->nbr_of_philos);
	left_philo = ((philo->id + 1) % table->nbr_of_philos);
	while (table->dinning && (table->philosophers[left_philo].eating
			|| table->philosophers[right_philo].eating))
	{
	}
}
