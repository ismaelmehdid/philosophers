/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:49:56 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/19 22:20:26 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/philosophers_bonus.h"

void	set_int(t_table *table, int *value, int new_value)
{
	sem_wait(table->data_semaphore);
	*value = new_value;
	sem_post(table->data_semaphore);
}

void	set_long(t_table *table, long *value, long new_value)
{
	sem_wait(table->data_semaphore);
	*value = new_value;
	sem_post(table->data_semaphore);
}

void	set_bool(t_table *table, bool *value, bool new_value)
{
	sem_wait(table->data_semaphore);
	*value = new_value;
	sem_post(table->data_semaphore);
}

void	increment_int(t_table *table, int *value)
{
	sem_wait(table->data_semaphore);
	(*value)++;
	sem_post(table->data_semaphore);
}
