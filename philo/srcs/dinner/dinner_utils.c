/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:40:36 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/13 17:04:06 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	print_message(t_philo *philo, t_types code)
{
	if (code == EAT)
		printf(
			"%ld %d is \033[32meating\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == SLEEP)
		printf(
			"%ld %d is \033[34msleeping\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == THINK)
		printf(
			"%ld %d is \033[33mthinking\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == FORK)
		printf(
			"%ld %d has \033[32mtaken a fork\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
	else if (code == DIE)
		printf(
			"%ld %d \033[91mdied\033[0m\n",
			get_elapsed_time(philo->table), philo->id);
}

int	wait_all_philosophers_to_start(t_table *table)
{
	set_int(
		table,
		&table->number_of_philosophers_ready,
		get_int(table, table->number_of_philosophers_ready) + 1);
	while (get_int(
		table,
		table->number_of_philosophers_ready) != table->number_of_philosophers)
	{
		usleep(1000);//TODO: loop leading to deadlock
	}
	if (get_long(table, table->started_time.tv_sec) == -1
		&& get_long(table, table->started_time.tv_usec == -1))
	{
		if (gettimeofday(&table->started_time, NULL) != 0) // check before if started_time is not set
		{
			write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
			return (1);
		}
	}
	return (0);
}

static void	eat_loop(t_table *table, t_philo *philo)
{
	long	time_to_finish;
	long	elapsed_time;

	elapsed_time = get_elapsed_time(table);
	if (elapsed_time == -1)
	{
		table->dinning = false;
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return ;
	}
	time_to_finish = elapsed_time + table->time_to_eat;
	print_message(philo, EAT);
	while (table->dinning == true && elapsed_time < time_to_finish)
	{
		elapsed_time = get_elapsed_time(table);
		if (elapsed_time == -1)
		{
			table->dinning = false;
			write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
			return ;
		}
	}
}

static void	sleep_loop(t_table *table, t_philo *philo)
{
	long	time_to_finish;
	long	elapsed_time;

	elapsed_time = get_elapsed_time(table);
	if (elapsed_time == -1)
	{
		table->dinning = false;
		write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
		return ;
	}
	time_to_finish = elapsed_time + table->time_to_sleep;
	print_message(philo, SLEEP);
	while (table->dinning == true && elapsed_time < time_to_finish)
	{
		elapsed_time = get_elapsed_time(table);
		if (elapsed_time == -1)
		{
			table->dinning = false;
			write (STDERR_FILENO, "Error while getting the time of the day\n", 41);
			return ;
		}
	}
}

void	wait_and_check(t_table *table, t_philo *philo, t_types type)
{
	if (type == EAT)
		eat_loop(table, philo);
	else if (type == SLEEP)
		sleep_loop(table, philo);
}