/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:38:59 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/15 20:03:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_a(t_ps_data *data)
{
	int		min;
	t_rots	rots;

	min = stack_minnum(data->a);
	if (data->a->num == min)
		return ;
	rots.cost_b = 0;
	rots.cost_a = rotations(data->a, data->lena, min);
	execute_rots_1(data, rots);
}

void	to_a(t_ps_data *data)
{
	t_rots	rots;
	t_rots	temp;
	int		min_ops;
	int		curr_ops;
	t_list	*b;

	b = data->b;
	while (data->lenb)
	{
		min_ops = ops_needed(get_rots(data, b->num, b->rank, 0));
		while (b->next)
		{
			temp = get_rots(data, b->num, b->rank, 0);
			curr_ops = ops_needed(temp);
			if (curr_ops <= min_ops)
			{
				rots = temp;
				min_ops = curr_ops;
			}
			b = b->next;
		}
		execute_rots_1(data, rots);
		pa(data);
	}
}
