/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:22 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/13 20:02:03 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	unsigned int	*data;

	data = NULL;
	if (argc < 5 || argc > 6)
	{
		write (2, "Error, Wrong arguments\n", 24);
		return (1);
	}
	data = check_set_data(argc, argv);
	if (!data)
		return (1);
	return (0);
	/*
	if (argc == 5)
	{
		
	}
	else if (argc == 6)
	{
		
	}
	*/
}