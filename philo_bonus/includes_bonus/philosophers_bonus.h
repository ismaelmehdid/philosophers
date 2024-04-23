/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:32 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/04/22 14:39:43 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//=== Includes ------------------------------------------------------------===//

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

//=== Data structures -----------------------------------------------------===//

typedef enum s_types{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE,
}	t_types;

typedef struct s_table {
	int					nbr_of_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					max_meals;
	sem_t				*forks;
	struct s_philospher	*philosophers;
	pthread_t			*monitor;
	bool				monitor_ready;
	struct timeval		started_time;
	int					nbr_of_philos_ready;
	sem_t				*data_semaphore;
	bool				dinning;
}t_table;

typedef struct s_philospher {
	int				id;
	pid_t			pid;
	long			last_meal;
	int				meals_remaining;
	t_table			*table;
	bool			eating;
}t_philo;

//=== Main functions ------------------------------------------------------===//

int		init_data(int argc, char **argv, t_table *table);
int		errors_handling(int argc, char **argv);

void	*dinner(void *arg);
void	*monitor(void *arg);
int		start_dinner(t_table *table);
void	synchronize_every_threads(t_table *table);
void	eating(t_table *table, t_philo *philo);
void	sleeping(t_table *table, t_philo *philo);
void	thinking(t_table *table, t_philo *philo);

void	precise_usleep(t_table *table, long microsec);

//=== Setters and getters -------------------------------------------------===//

int		get_int(t_table *table, int *value);
void	set_int(t_table *table, int *value, int new_value);
void	increment_int(t_table *table, int *value);

bool	get_bool(t_table *table, bool *value);
void	set_bool(t_table *table, bool *value, bool new_value);

long	get_long(t_table *table, long *value);
void	set_long(t_table *table, long *value, long new_value);

//=== Utilities -----------------------------------------------------------===//

bool	is_only_digits(char *array);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
void	destroy_all_semaphores(t_table *table);
void	free_all_threads_slots(t_table *table);
long	get_elapsed_time(t_table *table);

int		set_forks(t_table *table);
int		set_philosophers(t_table *table);
int		set_monitor(t_table *table);

void	print_message(t_philo *philo, t_types code);
void	destroy_and_free_everything(t_table *table);

//===----------------------------------------------------------------------===//

#endif