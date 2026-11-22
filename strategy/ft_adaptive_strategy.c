/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_strategy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:36:54 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/15 16:48:14 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	ft_pick_strategy(float disorder, int size)
{
	if (size <= 5 || disorder < 0.2f)
		return (STRATEGY_SIMPLE);
	if (disorder < 0.5f)
		return (STRATEGY_MEDIUM);
	return (STRATEGY_COMPLEX);
}

void	ft_run_strategy(t_list **a, t_list **b, int strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		ft_selection_sort(a, b);
	else if (strategy == STRATEGY_MEDIUM)
		ft_chunked_sort(a, b);
	else
		radix_sort(a, b);
}
