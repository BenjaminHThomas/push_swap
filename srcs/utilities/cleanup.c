/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:25:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/12 14:27:12 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arr(char **arr, t_ps_data *data)
{
	int	i;

	i = 1;
	while (i < data->ac)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_mem(t_ps_data *data)
{
	lst_clear(&data->a);
	lst_clear(&data->b);
	if (data->split_av)
		free_arr(data->av, data);
	if (data->sorted_av)
		free(data->sorted_av);
}
