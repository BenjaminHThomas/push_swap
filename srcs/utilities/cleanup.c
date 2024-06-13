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

void	free_mem(t_ps_data *data)
{
	lst_clear(&data->a);
	lst_clear(&data->b);
	if (data->sorted_av)
		free(data->sorted_av);
}
