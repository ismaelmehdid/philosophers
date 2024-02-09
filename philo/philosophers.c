/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:22 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/09 20:12:45 by ismaelmehdi      ###   ########.fr       */
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
	/*
	if (argc == 5)
	{
		
	}
	else if (argc == 6)
	{
		
	}
	*/
}