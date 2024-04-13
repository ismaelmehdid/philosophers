/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_and_setters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:12:13 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/13 16:35:27 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	get_int(t_table *table, int value)
{
	int	result;

	pthread_mutex_lock(&table->data_mutex);
	result = value;
	pthread_mutex_unlock(&table->data_mutex);
	return (result);
}

void	set_int(t_table *table, int *value, int new_value)
{
	pthread_mutex_lock(&table->data_mutex);
	*value = new_value;
	pthread_mutex_unlock(&table->data_mutex);
}

long	get_long(t_table *table, long value)
{
	long	result;

	pthread_mutex_lock(&table->data_mutex);
	result = value;
	pthread_mutex_unlock(&table->data_mutex);
	return (result);
}

void	set_long(t_table *table, long *value, long new_value)
{
	pthread_mutex_lock(&table->data_mutex);
	*value = new_value;
	pthread_mutex_unlock(&table->data_mutex);
}

bool	get_bool(t_table *table, bool value)
{
	bool	result;

	pthread_mutex_lock(&table->data_mutex);
	result = value;
	pthread_mutex_unlock(&table->data_mutex);
	return (result);
}

void	set_bool(t_table *table, bool *value, bool new_value)
{
	pthread_mutex_lock(&table->data_mutex);
	*value = new_value;
	pthread_mutex_unlock(&table->data_mutex);
}
