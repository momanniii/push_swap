/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_in_low.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:50:01 by wgharaib          #+#    #+#             */
/*   Updated: 2026/09/29 21:51:17 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_in_low(unsigned int c)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (c >= 16)
		count += ft_print_hex_in_low(c / 16);
	write (1, &hex[c % 16], 1);
	count ++;
	return (count);
}
