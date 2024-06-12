/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:44:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/12 13:24:40 by bthomas          ###   ########.fr       */
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
		return ;
	}
	plst = *lst;
	while (plst->next)
		plst = plst->next;
	plst->next = new;
	new->prev = plst;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		++count;
	}
	return (count);
}

void	lst_clear(t_list **list)
{
	t_list	*head;
	t_list	*pnext;

	if (!list || !*list)
		return ;
	head = *list;
	while (head)
	{
		pnext = head->next;
		free(head);
		head = pnext;
	}
	*list = NULL;
}
