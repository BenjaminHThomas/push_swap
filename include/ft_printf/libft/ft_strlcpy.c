/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:49:36 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:50:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*pd;
	const char	*ps;

	if (size == 0)
		return (ft_strlen(src));
	pd = dest;
	ps = src;
	while (size-- - 1 && *ps)
		*pd++ = *ps++;
	*pd = '\0';
	return (ft_strlen(src));
}
