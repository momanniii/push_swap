/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 22:23:06 by wgharaib          #+#    #+#             */
/*   Updated: 2026/10/01 00:09:55 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_address(unsigned long address)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (address >= 16)
		count += ft_print_address(address / 16);
	write (1, &hex[address % 16], 1);
	count ++;
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	write (1, "0x", 2);
	count = ft_print_address(address);
	return (count + 2);
}
