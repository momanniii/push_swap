/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:30:34 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/25 17:13:11 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	assign_index(t_list *stack)
{
	t_list	*temp;
	t_list	*current;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		temp = stack;
		while (temp)
		{
			if (temp->content < current->content)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}
