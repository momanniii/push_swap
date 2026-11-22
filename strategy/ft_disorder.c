/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:56:49 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/09 11:19:55 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static unsigned int	ft_count_mistake(t_list *stack, unsigned int *total_pairs)
{
	unsigned int	mistake;
	t_list			*temp;
	t_list			*next_temp;

	mistake = 0;
	temp = stack;
	while (temp)
	{
		next_temp = temp->next;
		while (next_temp)
		{
			(*total_pairs)++;
			if (temp->content > next_temp->content)
				mistake++;
			next_temp = next_temp->next;
		}
		temp = temp->next;
	}
	return (mistake);
}

float	ft_disorder(t_list **stack)
{
	unsigned int	size;
	unsigned int	total_pairs;
	unsigned int	mistake;

	if (!stack || !*stack)
		return (0.0f);
	size = ft_lstsize(*stack);
	if (size < 2)
		return (0.0f);
	total_pairs = 0;
	mistake = ft_count_mistake(*stack, &total_pairs);
	return ((float)mistake / total_pairs);
}
