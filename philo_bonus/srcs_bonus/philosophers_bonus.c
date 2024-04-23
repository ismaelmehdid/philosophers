/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:22 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/04/20 16:24:57 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_table			table;

	if (init_data(argc, argv, &table) != 0)
		return (1);
	if (start_dinner(&table) != 0)
		return (1);
	destroy_and_free_everything(&table);
	printf("end\n");
	return (0);
}
