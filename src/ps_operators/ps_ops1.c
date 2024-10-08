/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:13:34 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:44:10 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *a, t_list *b)
{
	int	temp_n;
	int	temp_rank;

	temp_n = a->num;
	temp_rank = a->rank;
	a->num = b->num;
	a->rank = b->rank;
	b->num = temp_n;
	b->rank = temp_rank;
}

/* Swap the first 2 elements at the top of stack a. */
void	sa(t_ps_data *data)
{
	if (data->lena <= 1)
		return ;
	swap(data->a, data->a->next);
}

/* Swap the first 2 elements at the top of stack b. */
void	sb(t_ps_data *data)
{
	if (data->lenb <= 1)
		return ;
	swap(data->b, data->b->next);
}

/* sa and sb at the same time. */
void	ss(t_ps_data *data)
{
	sa(data);
	sb(data);
	ft_printf("ss\n");
}

/* (push a): Take first element of b and put it at the top of a. */
void	pa(t_ps_data *data)
{
	t_list	*b_next;

	if (data->lenb == 0)
		return ;
	b_next = data->b->next;
	ft_lstadd_front(&data->a, data->b);
	data->b = b_next;
	data->lenb -= 1;
	data->lena += 1;
	ft_printf("pa\n");
}
