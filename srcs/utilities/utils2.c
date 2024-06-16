/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:02:32 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:43:57 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* used for positions not values, should never encounter min int */
int	int_abs(int n)
{
	if (n == MININT)
	{
		ft_printf("Error: Cannot return abs value of min int.\n");
		return (0);
	}
	if (n < 0)
		return (-n);
	return (n);
}

int	stack_minnum(t_list *list)
{
	int		min;
	t_list	*plist;

	if (!list)
		return (-1);
	min = MAXINT;
	plist = list;
	while (plist)
	{
		if (plist->num <= min)
			min = plist->num;
		plist = plist->next;
	}
	return (min);
}

int	get_pos(t_list *list, int n)
{
	int	pos;
	int	i;

	pos = -1;
	i = 0;
	while (list)
	{
		if (list->num == n)
		{
			pos = i;
			break ;
		}
		list = list->next;
		i++;
	}
	return (pos);
}

/* if both are positive, can use rr
	if both are negative, can use rrr
	else use ra/rb and rrb/rra seperately*/
int	ops_needed(t_rots rots)
{
	if (rots.cost_a >= 0 && rots.cost_b >= 0)
	{
		if (rots.cost_a > rots.cost_b)
			return (rots.cost_a);
		return (rots.cost_b);
	}
	else if (rots.cost_a <= 0 && rots.cost_b <= 0)
	{
		if (rots.cost_a < rots.cost_b)
			return (int_abs(rots.cost_a));
		return (int_abs(rots.cost_b));
	}
	return (int_abs(rots.cost_a) + int_abs(rots.cost_b));
}
