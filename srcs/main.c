/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:01:20 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 09:56:55 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	* to do:
* 	fix bug with : ./push_swap -31 -18 0 2 54 -21 -20 -31 1
0 20 -22 9

	implement: is_a_solvable();
		which then calls the same logic as to_b.
*/

int	main(int ac, char **av)
{
	t_ps_data	data;

	if (ac < 2)
		return (1);
	if (invalid_input(ac, av) || init(ac, av, &data))
	{
		write(2, "Error\n", 6);
		free_mem(&data);
		return (1);
	}
	if (!a_solvable(&data))
		sort(&data);
	else
		clean_a(&data);
	free_mem(&data);
	return (0);
}
