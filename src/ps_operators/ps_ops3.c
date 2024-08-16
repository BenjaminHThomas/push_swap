/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:10 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/14 11:08:37 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*lst_pretail(t_list *list)
{
	t_list	*tail;

	tail = list;
	while (tail->next->next)
		tail = tail->next;
	return (tail);
}

/* reverse rotate a: last el becomes first */
void	rra(t_ps_data *data)
{
	t_list	*tail;
	t_list	*pre_tail;

	if (data->lena <= 1)
		return ;
	tail = lst_last(data->a);
	pre_tail = lst_pretail(data->a);
	pre_tail->next = NULL;
	tail->prev = NULL;
	ft_lstadd_front(&data->a, tail);
}

/* reverse rotate b: last el becomes first */
void	rrb(t_ps_data *data)
{
	t_list	*tail;
	t_list	*pre_tail;

	if (data->lenb <= 1)
		return ;
	tail = lst_last(data->b);
	pre_tail = lst_pretail(data->b);
	pre_tail->next = NULL;
	tail->prev = NULL;
	ft_lstadd_front(&data->b, tail);
}

/* reverse rotate both a & b */
void	rrr(t_ps_data *data)
{
	rra(data);
	rrb(data);
}
