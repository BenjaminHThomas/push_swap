/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:23:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:45:03 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rots_2(t_ps_data *data, t_rots rots)
{
	while (rots.cost_a > 0)
	{
		rra(data);
		rots.cost_a--;
		ft_printf("rra\n");
	}
	while (rots.cost_b < 0)
	{
		rb(data);
		rots.cost_b++;
		ft_printf("rb\n");
	}
	while (rots.cost_b > 0)
	{
		rrb(data);
		rots.cost_b--;
		ft_printf("rrb\n");
	}
}

void	execute_rots_1(t_ps_data *data, t_rots rots)
{
	while (rots.cost_a < 0 && rots.cost_b < 0)
	{
		rr(data);
		rots.cost_a++;
		rots.cost_b++;
		ft_printf("rr\n");
	}
	while (rots.cost_a > 0 && rots.cost_b > 0)
	{
		rrr(data);
		rots.cost_a--;
		rots.cost_b--;
		ft_printf("rrr\n");
	}
	while (rots.cost_a < 0)
	{
		ra(data);
		rots.cost_a++;
		ft_printf("ra\n");
	}
	execute_rots_2(data, rots);
}

void	to_b(t_ps_data *data)
{
	t_rots	rots;
	t_rots	temp;
	int		min_ops;
	int		curr_ops;
	t_list	*a;

	while (data->lena > 2 && !a_solvable(data))
	{
		a = data->a;
		min_ops = MAXINT;
		while (a)
		{
			temp = get_rots(data, a->num, a->rank, 1);
			curr_ops = ops_needed(temp);
			if (curr_ops <= min_ops)
			{
				rots = temp;
				min_ops = curr_ops;
			}
			a = a->next;
		}
		execute_rots_1(data, rots);
		pb(data);
	}
}
