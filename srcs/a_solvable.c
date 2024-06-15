/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_solvable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:42:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/15 21:14:18 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	asc_check(t_list *a, int max)
{
	while (a->next)
	{
		if (a->num != max && a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	a_solvable(t_ps_data *data)
{
	t_list	*a;
	int		max;

	if (data->lena <= 2)
		return (1);
	a = data->a;
	max = stack_maxnum(a);
	return (asc_check(a, max));
}
