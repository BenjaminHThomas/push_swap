/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:57:00 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:49:45 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	c2;

	c2 = c;
	ps = (unsigned char *)s;
	while (n && *ps != c2)
	{
		ps++;
		n--;
	}
	if (n > 0 && *ps == c2)
		return ((void *)ps);
	return (NULL);
}
