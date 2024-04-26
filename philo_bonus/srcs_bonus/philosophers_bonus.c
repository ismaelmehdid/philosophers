/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:08:19 by imehdid           #+#    #+#             */
/*   Updated: 2024/04/26 18:27:35 by imehdid          ###   ########.fr       */
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
	return (0);
}
