/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:08:39 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/04/15 20:44:23 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	check_data(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) <= 0)
		{
			write (STDERR_FILENO,
				"One or several arguments are lower or equal to zero\n", 53);
			return (1);
		}
		if (is_only_digits(argv[i]) == false)
		{
			write (STDERR_FILENO, "The arguments are not only digits\n", 35);
			return (1);
		}
		i++;
	}
	return (0);
}

int	errors_handling(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write (STDERR_FILENO, "Error, Wrong number of arguments\n", 34);
		return (1);
	}
	if (check_data(argc, argv) != 0)
		return (1);
	return (0);
}
