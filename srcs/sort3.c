/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:38:59 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 08:31:06 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_optimal_pos_a(t_list *list, int listlen, int rank)
{
	t_list	*head;
	t_list	*optimal;
	int		diff;
	int		temp_diff;

	head = list;
	optimal = NULL;
	diff = MININT;
	while (head)
	{
		temp_diff = rank - head->rank;
		printf("Rank: %d, head->rank: %d diff: %d\n", rank, head->rank, temp_diff);
		if (temp_diff < 0 && temp_diff > diff)
		{
			diff = temp_diff;
			optimal = head;
			printf("Optimal = %d rank = %d diff = %d\n", head->num, head->rank, diff);
		}
		head = head->next;
	}
	if (optimal)
		return (rotations(list, listlen, optimal->num));
	printf("Couldn't find optimal\n");
	return (0);
}

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

	print_lists(data);
	while (data->lenb)
	{
		b = data->b;
		min_ops = MAXINT;
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
		printf("Cost A: %d, Cost B: %d\n", rots.cost_a, rots.cost_b);
		execute_rots_1(data, rots);
		pa(data);
		print_lists(data);
	}
}
