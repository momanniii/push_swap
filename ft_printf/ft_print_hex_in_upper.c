/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_in_upper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:57:22 by wgharaib          #+#    #+#             */
/*   Updated: 2026/09/29 21:50:58 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_in_upper(unsigned int c)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (c >= 16)
		count += ft_print_hex_in_upper(c / 16);
	write (1, &hex[c % 16], 1);
	count ++;
	return (count);
}
