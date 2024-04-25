/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:49:56 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/25 10:50:24 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

void	set_int(t_table *table, int *value, int new_value)
{
	pthread_mutex_lock(&table->data_mutex);
	*value = new_value;
	pthread_mutex_unlock(&table->data_mutex);
}

void	set_long(t_table *table, long *value, long new_value)
{
	pthread_mutex_lock(&table->data_mutex);
	*value = new_value;
	pthread_mutex_unlock(&table->data_mutex);
}

void	set_bool(t_table *table, bool *value, bool new_value)
{
	pthread_mutex_lock(&table->data_mutex);
	*value = new_value;
	pthread_mutex_unlock(&table->data_mutex);
}

void	increment_int(t_table *table, int *value)
{
	pthread_mutex_lock(&table->data_mutex);
	(*value)++;
	pthread_mutex_unlock(&table->data_mutex);
}

void	decrement_int(t_table *table, int *value)
{
	pthread_mutex_lock(&table->data_mutex);
	(*value)--;
	pthread_mutex_unlock(&table->data_mutex);
}
