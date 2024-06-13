/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:23:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/13 16:23:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rots(t_ps_data *data, t_rots *rots)
{
	while (rots->cost_a < 0 && rots->cost_b < 0)
	{
		rrr(data);
		rots->cost_a++;
		rots->cost_b++;
	}
	while (rots->cost_a > 0 && rots->cost_b > 0)
	{
		rr(data);
		rots->cost_a--;
		rots->cost_b--;
	}
	while (rots->cost_a < 0)
	{
		rra(data);
		rots->cost_a++;
	}
	while (rots->cost_a > 0)
	{
		ra(data);
		rots->cost_a--;
	}
	while (rots->cost_b < 0)
	{
		rrb(data);
		rots->cost_b++;
	}
	while (rots->cost_b > 0)
	{
		rb(data);
		rots->cost_b--;
	}
	pb(data);
	print_lists(data);
	debug_print(data);
}

void	to_b(t_ps_data *data)
{
	t_rots	rots;
	t_rots	temp;
	int		min_ops;
	int		curr_ops;
	t_list	*a;

	while (data->lena)
	{
		rots = get_rots(data, data->a->num, data->a->rank);
		min_ops = ops_needed(&rots);
		a = data->a;
		while (a->next)
		{
			temp = get_rots(data, a->num, a->rank);
			curr_ops = ops_needed(&temp);
			if (curr_ops <= min_ops)
			{
				rots = temp;
				min_ops = curr_ops;
			}
			a = a->next;
		}
		execute_rots(data, &rots);
	}
}
/*
	printf("A rotations needed: %d\n", rots.cost_a);
	printf("B rotations needed: %d\n", rots.cost_b);
	printf("Minimum ops: %d\n", min_ops);
*/