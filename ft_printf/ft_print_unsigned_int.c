/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:35:18 by wgharaib          #+#    #+#             */
/*   Updated: 2026/10/03 20:32:43 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(unsigned int c)
{
	unsigned int	i;
	unsigned int	count;

	i = c;
	count = 0;
	if (c >= 10)
		ft_print_unsigned_int(c / 10);
	ft_print_char((c % 10) + '0');
	if (i == 0)
		count ++;
	while (i != 0)
	{
		if (i == 0)
			count ++;
		i /= 10;
		count ++;
	}
	return (count);
}
