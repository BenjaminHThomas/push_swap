/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_solvable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:42:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 10:04:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	asc_check(t_list *a, int min, int max)
{
	t_list	*pa;

	pa = a;
	while (pa->next)
	{
		if (pa->num > pa->next->num)
		{
			if (pa->num != max)
				return (0);
			if (pa->next->num != min)
				return (0);
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
