/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:18:37 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:49:37 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (!dest && !src && n)
		return (dest);
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	while (n)
	{
		*pd++ = *ps++;
		n--;
	}
	return (dest);
}
