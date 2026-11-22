/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:21:25 by wgharaib          #+#    #+#             */
/*   Updated: 2026/09/23 21:29:28 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstl;
	size_t	srcl;

	i = 0;
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstl >= size)
	{
		return (size + srcl);
	}
	else
	{
		while (src[i] && dstl < size - 1)
		{
			dst[dstl] = src[i];
			dstl++;
			i++;
		}
		dst[dstl] = '\0';
	}
	return (srcl + (dstl - i));
}
