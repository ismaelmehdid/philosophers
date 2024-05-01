/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:22 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/04/29 18:45:26 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table			table;

	if (init_data(argc, argv, &table) != 0)
		return (1);
	if (start_dinner(&table) != 0)
		return (1);
	destroy_and_free_everything(&table);
	return (0);
}
