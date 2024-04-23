/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:58:51 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/18 20:26:06 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/philosophers_bonus.h"

long	ft_atol(const char *str)
{
	int		i;
	long	temp;
	int		countm;

	countm = 0;
	temp = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32
		|| str[i] == '+' || str[i] == '-')
	{
		if ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] == '+' || str[i + 1] == '-'
				|| (str[i + 1] >= 9 && str[i + 1] <= 13) || str[i + 1] == 32))
			return (0);
		if (str[i] == '-')
			countm++;
		i++;
	}
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		temp = temp * 10 + str[i++] - '0';
	if (countm == 1)
		return (-temp);
	return (temp);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	temp;
	int	countm;

	countm = 0;
	temp = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32
		|| str[i] == '+' || str[i] == '-')
	{
		if ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] == '+' || str[i + 1] == '-'
				|| (str[i + 1] >= 9 && str[i + 1] <= 13) || str[i + 1] == 32))
			return (0);
		if (str[i] == '-')
			countm++;
		i++;
	}
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		temp = temp * 10 + str[i++] - '0';
	if (countm == 1)
		return (-temp);
	return (temp);
}

bool	is_only_digits(char *array)
{
	int	i;

	i = 0;
	if (!array)
		return (false);
	while (array[i])
	{
		if (array[i] > '9' || array[i] < '0')
			return (false);
		i++;
	}
	return (true);
}
