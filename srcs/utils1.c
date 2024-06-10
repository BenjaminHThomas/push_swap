/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:02:57 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/10 10:52:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first 2 elements at the top of stack a. */
/*
void	sa(t_ps_data *data)
{
	
}*/

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
	while (i < (ac -1))
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
