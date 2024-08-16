/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:21:01 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:51:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* n is in list x, 
	how many operations would it take to get n to the top of list x?
 * */
int	rotations(t_list *list, int listlen, int n)
{
	int	rotats;
	int	pos;

	pos = get_pos(list, n);
	if (pos <= listlen / 2)
		rotats = -pos;
	else
		rotats = listlen - pos;
	return (rotats);
}

/* the rank isn't min or max in the list, where does it fit in? */
int	get_optimal_pos_b(t_list *list, int listlen, int rank)
{
	t_list	*head;
	t_list	*optimal;
	int		diff;
	int		temp_diff;

	head = list;
	optimal = NULL;
	diff = MAXINT;
	while (head)
	{
		temp_diff = rank - head->rank;
		if (temp_diff > 0 && temp_diff < diff)
		{
			diff = temp_diff;
			optimal = head;
		}
		head = head->next;
	}
	if (optimal)
		return (rotations(list, listlen, optimal->num));
	return (rotations(list, listlen, stack_maxnum(list)));
}

t_rots	get_rots(t_ps_data *data, int n, int rank, int to_b)
{
	t_rots	rots;

	if (to_b)
	{
		rots.cost_a = rotations(data->a, data->lena, n);
		rots.cost_b = get_optimal_pos_b(data->b, data->lenb, rank);
	}
	else
	{
		rots.cost_a = get_optimal_pos_a(data->a, data->lena, rank);
		rots.cost_b = rotations(data->b, data->lenb, n);
	}
	return (rots);
}

void	sort(t_ps_data *data)
{
	if (data->lena > 3)
	{
		pb(data);
		pb(data);
	}
	else
	{
		sa(data);
		ft_printf("sa\n");
	}
	to_b(data);
	to_a(data);
	clean_a(data);
}
