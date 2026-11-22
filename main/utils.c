/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalmoma <abalmoma@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:13:31 by abalmoma          #+#    #+#             */
/*   Updated: 2026/11/14 21:26:58 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	*arr(t_list *a)
{
	int				*values;
	unsigned int	size;
	int				i;

	size = ft_lstsize(a);
	values = malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	i = 0;
	while (a)
	{
		values[i] = a->content;
		i++;
		a = a->next;
	}
	return (values);
}

void	node_back(t_list **head, t_list *new_node)
{
	t_list	*last_node;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last_node = ft_lstlast(*head);
	last_node->next = new_node;
}

void	freesplit(char **splitarr)
{
	int	i;

	if (!splitarr)
		return ;
	i = 0;
	while (splitarr[i])
	{
		free(splitarr[i]);
		i++;
	}
	free(splitarr);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
