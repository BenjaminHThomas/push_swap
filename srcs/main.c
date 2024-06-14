/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:01:20 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/14 13:24:42 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort(&data);
	free_mem(&data);
	return (0);
}
