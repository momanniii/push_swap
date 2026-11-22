/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 21:24:21 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/14 21:24:26 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	*ft_get_counts(void)
{
	static int	counts[11];

	return (counts);
}

char	**ft_get_names(void)
{
	static char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};

	return (names);
}

void	ft_print_op(char *op)
{
	int		i;
	char	**names;

	names = ft_get_names();
	i = 0;
	while (i < 11 && ft_strncmp(op, names[i], 4) != 0)
		i++;
	if (i < 11)
		ft_get_counts()[i]++;
	ft_printf("%s\n", op);
}
