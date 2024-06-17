/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:44:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/15 19:29:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int n)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	newlst->num = n;
	newlst->next = NULL;
	newlst->prev = NULL;
	return (newlst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plst;

	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	plst = *lst;
	while (plst->next)
		plst = plst->next;
	plst->next = new;
	new->prev = plst;
	new->next = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}

void	lst_clear(t_list *list)
{
	t_list	*head;
	t_list	*pnext;

	if (!list)
		return ;
	head = list;
	while (head)
	{
		pnext = head->next;
		free(head);
		head = pnext;
	}
	list = NULL;
}

t_list	*lst_last(t_list *list)
{
	t_list	*tail;

	tail = list;
	while (tail->next)
		tail = tail->next;
	return (tail);
}
