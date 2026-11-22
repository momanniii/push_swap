/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:40:47 by wgharaib          #+#    #+#             */
/*   Updated: 2026/10/03 20:42:24 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print(long c)
{
	if (c < 0)
	{
		write (1, "-", 1);
		c = -c;
	}
	if (c >= 10)
		ft_print(c / 10);
	ft_print_char((c % 10) + '0');
}

int	ft_print_num(int c)
{
	long	i;
	int		count;

	i = c;
	count = 0;
	ft_print(i);
	if (i == 0)
		count ++;
	while (i != 0)
	{
		if (i < 0)
		{
			count++;
			i = -i;
		}
		i /= 10;
		count++;
	}
	return (count);
}
