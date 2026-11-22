/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 21:24:38 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/14 21:24:44 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static void	put_percent(float disorder)
{
	int	v;

	v = (int)(disorder * 10000.0f + 0.5f);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(v / 100, 2);
	ft_putchar_fd('.', 2);
	if (v % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(v % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(int adaptive, int strategy)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (adaptive)
		ft_putstr_fd("Adaptive / ", 2);
	else if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple / ", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Medium / ", 2);
	else
		ft_putstr_fd("Complex / ", 2);
	if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("O(n\xe2\x88\x9an)\n", 2);
	else
		ft_putstr_fd("O(n log n)\n", 2);
}

static int	total_ops(void)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += ft_get_counts()[i];
		i++;
	}
	return (total);
}

static void	print_counts(int from, int to)
{
	ft_putstr_fd("[bench]", 2);
	while (from < to)
	{
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(ft_get_names()[from], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(ft_get_counts()[from], 2);
		from++;
	}
	ft_putchar_fd('\n', 2);
}

void	ft_print_bench(float disorder, int adaptive, int strategy)
{
	put_percent(disorder);
	print_strategy(adaptive, strategy);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(), 2);
	ft_putchar_fd('\n', 2);
	print_counts(0, 5);
	print_counts(5, 11);
}
