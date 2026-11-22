/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:24:05 by wgharaib          #+#    #+#             */
/*   Updated: 2026/09/16 21:53:11 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	count;

	count = ft_len(n);
	num = n;
	if (n < 0)
		num = -num;
	str = malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	while (count != 0)
	{
		str[count - 1] = ((num % 10) + '0');
		num /= 10;
		count--;
	}
	if (n < 0)
		str[count] = '-';
	return (str);
}
