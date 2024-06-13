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

/* n is in list x, 
	how many operations would it take to get n to the top of list x?
 *
 * if negative, rra / rrb
 * if positive, ra / rb
 * */
static int	rotations(t_list *list, int listlen, int n)
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

int	get_optimal_pos(t_list *list, int listlen, int rank)
{
	t_list	*head;
	t_list	*tail;

	head = list;
	tail = list;
	while (tail->next)
		tail = tail->next;
	if (rank > head->rank)
		return (0);
	while (head && !(rank > head->rank))
		head = head->next;
	if (!head)
	{
		printf("Error: can't find optimal pos\n");
		return (0);
	}
	return (rotations(list, listlen, head->num));
}

/* n is in a/b, assuming n is at the top, how many rotations of a/b
 * for it to be correctly positioned in a/b?
 *
 * if negative, rrb/rra
 * if positive, rb/ra
 */
static int	cost(t_list *list, int listlen, int n, int rank)
{
	int	max;
	int	min;

	max = stack_maxnum(list);
	min = stack_minnum(list);
	if (n >= max)
		return (rotations(list, listlen, max));
	else if (n <= min)
		return (rotations(list, listlen, min));
	else
		return (get_optimal_pos(list, listlen, rank));
}

t_rots	get_rots(t_ps_data *data, int n, int rank)
{
	t_rots	rots;

	rots.cost_a = rotations(data->a, data->lena, n);
	rots.cost_b = cost(data->b, data->lenb, n, rank);
	return (rots);
}

void	sort(t_ps_data *data)
{
	

	pb(data);
	pb(data);
	print_lists(data);
	//debug_print(data);
	printf("\n");
	to_b(data);
}
