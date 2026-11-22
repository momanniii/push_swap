/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 00:03:02 by wgharaib          #+#    #+#             */
/*   Updated: 2026/09/13 00:16:14 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*y1;
	const unsigned char	*y2;

	i = 0;
	y1 = (const unsigned char *)s1;
	y2 = (const unsigned char *)s2;
	while (i < n)
	{
		if ((y1[i] > y2[i]) || (y1[i] < y2[i]))
			return (y1[i] - y2[i]);
		i++;
	}
	return (0);
}
