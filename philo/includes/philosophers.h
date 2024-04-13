/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:32 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/04/13 16:41:33 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

//=== Data structures -----------------------------------------------------===//

typedef enum s_types{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE,
} t_types;

typedef struct s_table {
	int					number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					max_meals; // OPTIONAL : -1 if not set
	pthread_mutex_t		*forks;
	struct s_philospher	*philosophers;
	pthread_t			*monitor;
	struct timeval		started_time;
	int					number_of_philosophers_ready;
	pthread_mutex_t		data_mutex;
	bool				dinning;
}t_table;

typedef struct s_philospher {
	int				id;
	pthread_t		*thread_id;
	long			last_meal;
	int				meals_remaining; // OPTIONAL : -1 if not set
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
	bool			eating;
}t_philo;

//=== Main functions ------------------------------------------------------===//

int		init_data(int argc, char **argv, t_table *table);
int		errors_handling(int argc, char **argv);

void	*dinner(void *arg);
void	*monitor(void *arg);
int		start_dinner(t_table *table);
void	eating(t_table *table, t_philo *philo);
void	sleeping(t_table *table, t_philo *philo);
void	thinking(t_table *table, t_philo *philo);
void	wait_and_check(t_table *table, t_philo *philo, t_types type);
int		wait_all_philosophers_to_start(t_table *table);
int		philosophers_threads_init(t_table *table);
int		philosophers_threads_joiner(t_table *table);
void	*check_all_philos_status(t_table *table);

//=== Setters and getters -------------------------------------------------===//

int		get_int(t_table *table, int value);
void	set_int(t_table *table, int *value, int new_value);

bool	get_bool(t_table *table, bool value);
void	set_bool(t_table *table, bool *value, bool new_value);

long	get_long(t_table *table, long value);
void	set_long(t_table *table, long *value, long new_value);

//=== Utilities -----------------------------------------------------------===//

bool	is_only_digits(char *array);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
void	destroy_all_mutexes(t_table *table);
void	free_all_threads_slots(t_table *table);
long	get_elapsed_time(t_table *table);

int		set_forks(t_table *table);
int		set_philosophers(t_table *table);
int		set_monitor(t_table *table);

void	print_message(t_philo *philo, t_types code);
void	destroy_and_free_everything(t_table *table);

//===----------------------------------------------------------------------===//

#endif