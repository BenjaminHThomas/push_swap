/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_numcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:29:10 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/17 12:29:11 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	invalid_num(char *s)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	res = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	res *= sign;
	if (res > MAXINT || res < MININT)
		return (1);
	return (0);
}

/* Greater than maxint or less than minint */
static int	invalid_nums(int ac, char **av)
{
	int	idx;

	idx = 1;
	while (idx < ac - 1)
	{
		if (invalid_num(av[idx]))
			return (1);
		idx++;
	}
	return (0);
}

static int	non_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '-')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_input(int ac, char **av)
{
	if (non_digits(ac, av))
		return (1);
	if (invalid_nums(ac, av))
		return (1);
	return (0);
}
