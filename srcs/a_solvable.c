/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_solvable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:42:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/15 19:50:37 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	asc_check(t_list *a, int min, int max);

static int	desc_check(t_list *a, int min, int max)
{
	while (a->next)
	{
		if (a->num == min && a->next->num == max)
			return (asc_check(a->next, min, max));
		if (a->num < a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	asc_check(t_list *a, int min, int max)
{
	while (a->next)
	{
		if (a->num == max && a->next->num == min)
			return (desc_check(a->next, min, max));
		if (a->num > a->next->num)
			return (0);
		a = a->next;
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
	if (a->num == min)
		return (asc_check(a, min, max));
	if (a->num == max)
		return (desc_check(a, min, max));
	if (a->num > a->next->num)
		return (desc_check(a, min, max));
	return (asc_check(a, min, max));
}
