/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:08:39 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/13 20:01:58 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static unsigned int	ft_atoi_uint(const char *str)
{
	int				i;
	unsigned int	temp;

	temp = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		temp = temp * 10 + str[i++] - '0';
	return (temp);
}

static int	is_only_digits(char *array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		if (array[i] >= '9' || array[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

static int	check_data(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_only_digits(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static unsigned int	*set_data(int argc, char **argv)
{
	int				j;
	int				i;
	unsigned int	*data;
	
	j = 0;
	i = 1;
	data = malloc(sizeof(unsigned int) * argc);
	if (!data)
		return (NULL);
	while (i < argc)
	{
		data[j] = ft_atoi_uint(argv[i]);
		i++;
		j++;
	}
	return (data);
}

unsigned int	*check_set_data(int argc, char **argv)
{
	if (!check_data(argc, argv))
		return (NULL);
	return (set_data(argc, argv));
}