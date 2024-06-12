/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:13:50 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/12 13:35:52 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* (push b): Take first element of a and put it at the top of b. */
void	pb(t_ps_data *data)
{
	t_list	*a_next;

	if (ft_lstsize(data->a) == 0)
		return ;
	a_next = data->a->next;
	ft_lstadd_front(&data->b, data->a);
	data->a = a_next;
	data->lena -= 1;
	data->lenb += 1;
}

/* (rotate a) first element moves to last */
void	ra(t_ps_data *data)
{
	t_list	*temp;

	if (ft_lstsize(data->a) <= 1)
		return ;
	temp = data->a;
	data->a = temp->next;
	temp->next = NULL;
	ft_lstadd_back(&data->a, temp);
}

/* (rotate b) first element moves to last */
void	rb(t_ps_data *data)
{
	t_list	*temp;

	if (ft_lstsize(data->b) <= 1)
		return ;
	temp = data->b;
	data->b = temp->next;
	temp->next = NULL;
	ft_lstadd_back(&data->b, temp);
}

/* both ra and rb */
void	rr(t_ps_data *data)
{
	ra(data);
	rb(data);
}
