/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:02:32 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/11 12:02:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_optimal_pos(t_list *list, int listsize, int n)
{
	t_list	*b;
	int		pos;
	int		max;
	int		max_pos;
	int		prev;

	// [0, 1, 5, 2, 3, 4]
	// len = 6;
	// max = 5;
	// maxpos = 2;
	// len / 2 = 3;
	pos = 0;
	b = list;
	max = stack_maxnum(b);
	max_pos = get_pos(b, max);
	if (n >= max || n <= stack_minnum(b))
	{
		if (max_pos <= listsize / 2)
			return (max_pos);
		else
			return (listsize - pos);
	}
	while (b->next)
	{
		prev = b->num;
		b = b->next;
		if (prev < n)
	}
}