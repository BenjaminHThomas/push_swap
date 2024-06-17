/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:09:16 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/17 16:09:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_space(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	replace_av(char **av, t_ps_data *data)
{
	char	**new_av;
	int		len;
	int		i;

	data->split_av = 0;
	new_av = ft_split(av[1], ' ');
	if (!new_av)
		return (1);
	len = 0;
	while (new_av[len])
		len++;
	data->av = (char **)malloc((len + 1) * sizeof(char *));
	if (!data->av)
	{
		free(new_av);
		return (1);
	}
	data->av[0] = av[0];
	i = 0;
	while (i < len)
	{
		data->av[i + 1] = new_av[i];
		i++;
	}
	free(new_av);
	data->ac = len + 1;
	data->split_av = 1;
	return (0);
}
