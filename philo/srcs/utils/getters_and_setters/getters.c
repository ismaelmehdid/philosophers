/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:50:03 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/25 10:50:26 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

int	get_int(t_table *table, int *value)
{
	int	result;

	pthread_mutex_lock(&table->data_mutex);
	result = *value;
	pthread_mutex_unlock(&table->data_mutex);
	return (result);
}

long	get_long(t_table *table, long *value)
{
	long	result;

	pthread_mutex_lock(&table->data_mutex);
	result = *value;
	pthread_mutex_unlock(&table->data_mutex);
	return (result);
}

bool	get_bool(t_table *table, bool *value)
{
	bool	result;

	pthread_mutex_lock(&table->data_mutex);
	result = *value;
	pthread_mutex_unlock(&table->data_mutex);
	return (result);
}
