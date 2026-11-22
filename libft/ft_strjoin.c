/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 21:12:06 by wgharaib          #+#    #+#             */
/*   Updated: 2026/09/15 21:30:16 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*newstr;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	newstr = malloc(len + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		newstr[j] = s2[i];
		j++;
		i++;
	}
	newstr[j] = '\0';
	return (newstr);
}
