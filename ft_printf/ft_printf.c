/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:50:07 by wgharaib          #+#    #+#             */
/*   Updated: 2026/10/01 00:10:04 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversions(char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = ft_print_char(va_arg(args, int));
	if (s == 's')
		count = ft_print_string(va_arg(args, char *));
	if (s == 'd' || s == 'i')
		count = ft_print_num(va_arg(args, int));
	if (s == 'p')
		count = ft_print_pointer(va_arg(args, void *));
	if (s == 'u')
		count = ft_print_unsigned_int(va_arg(args, unsigned int));
	if (s == 'x')
		count = ft_print_hex_in_low(va_arg(args, unsigned int));
	if (s == 'X')
		count = ft_print_hex_in_upper(va_arg(args, unsigned int));
	if (s == '%')
		count = ft_print_char('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			count;
	va_list		args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_conversions(s[i + 1], args);
			i++;
		}
		else
		{
			write (1, &s[i], 1);
			count ++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
