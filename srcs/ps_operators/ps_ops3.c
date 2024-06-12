/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:13:10 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/12 13:37:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse rotate a: last el becomes first */
void	rra(t_ps_data *data)
{
	t_list	*p_list;
	t_list	*p_next;

	if (data->lena <= 1)
		return ;
	p_list = data->a;
	p_next = p_list->next;
	while (p_next->next)
	{
		p_list = p_next;
		p_next = p_list->next;
	}
	p_list->next = NULL;
	ft_lstadd_front(&data->a, p_next);
}

/* reverse rotate b: last el becomes first */
void	rrb(t_ps_data *data)
{
	t_list	*p_list;
	t_list	*p_next;

	if (data->lenb <= 1)
		return ;
	p_list = data->b;
	p_next = p_list->next;
	while (p_next->next)
	{
		p_list = p_next;
		p_next = p_list->next;
	}
	p_list->next = NULL;
	ft_lstadd_front(&data->b, p_next);
}

/* reverse rotate both a & b */
void	rrr(t_ps_data *data)
{
	rra(data);
	rrb(data);
}
