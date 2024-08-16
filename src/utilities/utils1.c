/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:02:57 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:43:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_ps_data *data)
{
	t_list	*a;
	t_list	*b;

	printf("\n%10c %10c\n\n", 'A', 'B');
	a = data->a;
	b = data->b;
	while (a || b)
	{
		if (a && b)
			ft_printf("%10d %10d\n", a->num, b->num);
		else if (a && !b)
			ft_printf("%10d %10c\n", a->num, ' ');
		else if (!a && b)
			ft_printf("%10c %10d\n", ' ', b->num);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("\n");
}

int	stack_maxnum(t_list *list)
{
	int		max;
	t_list	*plist;

	if (!list)
		return (-1);
	max = MININT;
	plist = list;
	while (plist)
	{
		if (plist->num > max)
			max = plist->num;
		plist = plist->next;
	}
	return (max);
}

void	print_ranks(t_list *list)
{
	while (list)
	{
		ft_printf("num %10d rank %10d\n", list->num, list->rank);
		list = list->next;
	}
}

int	numlen(long int n)
{
	int	numlen;

	if (n == 0)
		return (1);
	numlen = 0;
	while (n)
	{
		n /= 10;
		numlen++;
	}
	return (numlen);
}
