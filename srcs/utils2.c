/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:02:32 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/11 12:02:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	get_pos(t_list *list, int n)
{
	int	pos;
	int	i;

	pos = -1;
	i = 0;
	while (list)
	{
		if (list->num == n)
		{
			pos = i;
			break ;
		}
		list = list->next;
		i++;
	}
	return (pos);
}

int	get_optimal_pos(t_list *list, int listsize, int n)
{
	t_list	*b;
	int		pos;
	int		max;
	int		max_pos;

	// [0, 1, 5, 2, 3, 4]
	// len = 6;
	// max = 5;
	// maxpos = 2;
	// len / 2 = 3;
	pos = 0;
	b = list;
	max = stack_maxnum(b);
	max_pos = get_pos(b, max);
	if (n >= max)
	{
		if (max_pos <= listsize / 2)
			return (max_pos);
		else
			return (listsize - pos);
	}
	while (b)
}