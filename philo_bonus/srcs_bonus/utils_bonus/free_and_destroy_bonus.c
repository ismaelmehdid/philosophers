/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:29:59 by imehdid           #+#    #+#             */
/*   Updated: 2024/05/01 21:38:11 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

static void	destroy_all_semaphores_util(t_table *table, int *errors)
{
	if (sem_close(table->forks_protection) == -1)
	{
		write (STDERR_FILENO, "Error while closing a semaphore\n", 33);
		(*errors)++;
	}
	if (sem_unlink("/forks_protection") == -1)
	{
		write (STDERR_FILENO, "Error while unlinking a semaphore\n", 35);
		(*errors)++;
	}
	if (sem_close(table->end) == -1)
	{
		write (STDERR_FILENO, "Error while closing a semaphore\n", 33);
		(*errors)++;
	}
	if (sem_unlink("/end") == -1)
	{
		write (STDERR_FILENO, "Error while unlinking a semaphore\n", 35);
		(*errors)++;
	}
	if (*errors > 0)
		exit(EXIT_FAILURE);
}

void	destroy_all_semaphores(t_table *table)
{
	int	errors;

	errors = 0;
	if (sem_close(table->data_semaphore) == -1)
	{
		write (STDERR_FILENO, "Error while closing a semaphore\n", 33);
		errors++;
	}
	if (sem_unlink("/data_semaphore") == -1)
	{
		write (STDERR_FILENO, "Error while unlinking a semaphore\n", 35);
		errors++;
	}
	if (sem_close(table->forks) == -1)
	{
		write (STDERR_FILENO, "Error while closing a semaphore\n", 33);
		errors++;
	}
	if (sem_unlink("/forks") == -1)
	{
		write (STDERR_FILENO, "Error while unlinking a semaphore\n", 35);
		errors++;
	}
	destroy_all_semaphores_util(table, &errors);
}

void	destroy_and_free_everything(t_table *table)
{
	if (table->philosophers)
		free(table->philosophers);
	destroy_all_semaphores(table);
}
