/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_solvable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:42:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/18 11:02:59 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	asc_check(t_list *a, int min, int max)
{
	t_list	*pa;
	int		pivot_found;

	pa = a;
	pivot_found = 0;
	while (pa->next)
	{
		if (pa->num > pa->next->num)
		{
			if (pa->num != max || pa->next->num != min || pivot_found)
				return (0);
			pivot_found = 1;
		}
		pa = pa->next;
	}
	return (1);
}

int	a_solvable(t_ps_data *data)
{
	t_list	*a;
	int		min;
	int		max;

	if (data->lena <= 2)
		return (1);
	a = data->a;
	min = stack_minnum(a);
	max = stack_maxnum(a);
	return (asc_check(a, min, max));
}
