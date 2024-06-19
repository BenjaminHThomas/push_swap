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

int	is_space(unsigned char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	invalid_num(char *s)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (is_space(s[i]))
		i++;
	if ((s[i] == '-' || s[i] == '+') && s[i])
	{
		sign = 1 - (2 * (s[i] == '-'));
		i++;
	}
	while (ft_isdigit(s[i])
		&& ((res + 1) / 10 < MAXINT && (res + 1) / 10 > MININT))
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	if (res * sign > MAXINT || res * sign < MININT || numlen(res) > 10)
		return (1);
	return (0);
}

/* Greater than maxint or less than minint */
static int	invalid_nums(int ac, char **av)
{
	int	idx;

	idx = 1;
	while (idx < ac)
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
		while (av[i] && is_space(av[i][j]))
			j++;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i] && av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_input(int ac, char **av, t_ps_data *data)
{
	data->sorted_av = NULL;
	if (ac == 2 && contains_space(av[1]))
	{
		if (replace_av(av, data))
			return (1);
	}
	else
	{
		data->ac = ac;
		data->av = av;
		data->split_av = 0;
	}
	if (non_digits(data->ac, data->av))
		return (1);
	if (invalid_nums(data->ac, data->av))
		return (1);
	return (0);
}
