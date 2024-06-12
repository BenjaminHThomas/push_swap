/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:21:01 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/12 18:20:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* n is in a, how many operations would it take to push into b in 
 * the correct order? */
/*
int	cost(t_ps_data *data, int n)
{
	int	min_cost;
	int	size_a;
	int	size_b;
	int	pos;

	size_a = ft_lstsize(data->a);
	size_b = ft_lstsize(data->a);
	pos = get_pos(data->a, n);
	// calc steps to rotate a so n is at the top
	if (pos <= size_a / 2)
		min_cost = pos;
	else
		min_cost = size_a - pos;
	// determine optimal position in b for n

	// calc steps to rotate b to that pos
}
*/
void	sort(t_ps_data *data)
{
	// 1. push first two numbers to stack b
	pb(data);
	pb(data);
	print_lists(data);
	/* 2. find "cheapest" number - which one costs the fewest
	* operations to place into correct position in b */

}
