/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:21:01 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/15 20:19:02 by bthomas          ###   ########.fr       */
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
int	get_optimal_pos(t_list *list, int listlen, int rank)
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
	printf("Optimal not found...\n");
	return (0);
}

/* n is in a, assuming n is at the top of a, how many rotations of b
 * for it to be correctly positioned in b? */
static int	cost(t_list *list, int listlen, int n, int rank)
{
	int	max;
	int	min;

	max = stack_maxnum(list);
	min = stack_minnum(list);
	if (n >= max || n <= min)
		return (rotations(list, listlen, max));
	else
		return (get_optimal_pos(list, listlen, rank));
}

t_rots	get_rots(t_ps_data *data, int n, int rank, int is_to_b)
{
	t_rots	rots;

	if (is_to_b)
	{
		rots.cost_a = rotations(data->a, data->lena, n);
		rots.cost_b = cost(data->b, data->lenb, n, rank);
	}
	else
	{
		rots.cost_a = cost(data->a, data->lena, n, rank);
		rots.cost_b = rotations(data->b, data->lenb, n);
	}
	return (rots);
}

void	sort(t_ps_data *data)
{
	pb(data);
	pb(data);
	to_b(data);
	to_a(data);
	clean_a(data);
}
