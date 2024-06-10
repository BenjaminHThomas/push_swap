/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:02:57 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/10 15:28:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	invalid_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init(int ac, char **av, t_ps_data *data)
{
	int		i;
	t_list	*temp;

	data->a = ft_lstnew(ft_atoi(av[1]));
	if (!data->a)
		return (1);
	i = 2;
	while (i < ac)
	{
		temp = ft_lstnew(ft_atoi(av[i]));
		if (!temp)
			return (1);
		ft_lstadd_back(&data->a, temp);
		i++;
	}
	data->ac = ac;
	data->b = NULL;
	return (0);
}

void	free_mem(t_ps_data *data)
{
	lst_clear(&data->a);
	lst_clear(&data->b);
}

void	print_list(t_list *list)
{
	if (!list)
		return ;
	while (list)
	{
		printf("%d\n", list->num);
		list = list->next;
	}
}

int	stack_maxnum(t_list *list)
{
	int		max;
	t_list	plist;

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
