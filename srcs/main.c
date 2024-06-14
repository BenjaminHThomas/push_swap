/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:01:20 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/10 15:22:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	test_ops(t_ps_data *data)
{
	printf("List a pre-test:\n");
	print_list(data->a);
	printf("\nCommencing test...\n");
	printf("\nswap function:\n");
	sa(data);
	print_list(data->a);
	printf("\npush function:\n");
	pb(data);
	printf("printing a:\n");
	print_list(data->a);
	printf("printing b:\n");
	print_list(data->b);
	printf("\nrotating a:\n");
	ra(data);
	print_list(data->a);
	printf("\nreverse rotating a:\n");
	rra(data);
	print_list(data->a);
}
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
	sort(&data);
	free_mem(&data);
	return (0);
}
