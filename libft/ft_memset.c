/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:54:45 by wgharaib          #+#    #+#             */
/*   Updated: 2026/09/22 19:49:17 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int b, size_t c)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = a;
	while (i < c)
	{
		p[i] = (unsigned char)b;
		i++;
	}
	return (a);
}
