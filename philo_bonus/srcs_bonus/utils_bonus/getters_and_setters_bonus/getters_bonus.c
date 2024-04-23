/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:50:03 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/19 22:20:41 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/philosophers_bonus.h"

int	get_int(t_table *table, int *value)
{
	int	result;

	sem_wait(table->data_semaphore);
	result = *value;
	sem_post(table->data_semaphore);
	return (result);
}

long	get_long(t_table *table, long *value)
{
	long	result;

	sem_wait(table->data_semaphore);
	result = *value;
	sem_post(table->data_semaphore);
	return (result);
}

bool	get_bool(t_table *table, bool *value)
{
	bool	result;

	sem_wait(table->data_semaphore);
	result = *value;
	sem_post(table->data_semaphore);
	return (result);
}
