/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:21:01 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/13 12:38:04 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* n is in a, how many operations would it take to get n to the top of a
 *
 * if negative, rra
 * if positive, ra
 * */
static int	costa(t_ps_data *data, int n)
{
	int	costa;
	int	pos;

	pos = get_pos(data->a, n);
	if (pos <= data->lena / 2);
		costa = -pos;
	else
		costa = size_a - pos;
	return (costa);
}

/* n is in a, assuming a is at the top, how many rotations of b
 * for it to be correctly positioned in b?
 *
 * if negative, rrb
 * if positive, rb
 */
static int	costa_b(t_ps_data *data, int n)
{
	int	pos;
	int	maxb;
	int	minb;
	int	costb;

	maxb = stack_maxnum(data->b);
	minb = stack_minnum(data->b);
}

int	cost(t_ps_data *data, int n)
{
	int	a_cost;
	int	b_cost;
	int	pos;

	pos = get_pos(data->a, n);
	// calc steps to rotate a so n is at the top
	costa = costa(data, n);
	// determine optimal position in b for n

	// calc steps to rotate b to that pos
}

void	sort(t_ps_data *data)
{
	// 1. push first two numbers to stack b
	pb(data);
	pb(data);
	ra(data);
	rb(data);
	pa(data);
	pb(data);
	pb(data);
	pb(data);
	print_lists(data);
	debug_print(data);
	/* 2. find "cheapest" number - which one costs the fewest
	* operations to place into correct position in b */
}
