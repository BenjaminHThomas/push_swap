/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:08:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/15 18:44:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplicates(t_ps_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lena - 1)
	{
		j = i + 1;
		while (j < data->lena)
		{
			if (data->sorted_av[i] == data->sorted_av[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	rank_list(t_ps_data *data, char **av)
{
	int		pos;
	t_list	*a;

	data->sorted_av = (int *)malloc(sizeof(int) * (data->lena));
	if (!data->sorted_av)
		return (1);
	pos = 0;
	while (++pos < data->ac)
		data->sorted_av[pos - 1] = ft_atoi(av[pos]);
	quicksort(data->sorted_av, 0, data->lena - 1);
	if (duplicates(data))
		return (1);
	pos = 0;
	a = data->a;
	while (a)
	{
		pos = 0;
		while (data->sorted_av[pos] != a->num)
			pos++;
		a->rank = pos;
		a = a->next;
	}
	return (0);
}

int	init(int ac, char **av, t_ps_data *data)
{
	int		i;
	t_list	*temp;

	data->a = NULL;
	data->b = NULL;
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
	data->lena = ac - 1;
	data->lenb = 0;
	data->b = NULL;
	return (rank_list(data, av));
}
