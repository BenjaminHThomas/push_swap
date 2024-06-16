/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:57:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:50:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (!dest && !src && n)
		return (dest);
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	if (pd < ps)
		while (n--)
			*pd++ = *ps++;
	else
	{
		pd += n;
		ps += n;
		while (n--)
			*--pd = *--ps;
	}
	return (dest);
}
