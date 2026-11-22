/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:14:49 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/11 21:15:52 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	process_numbers(char **split, t_list **stack_a)
{
	int		j;
	long	num;
	t_list	*node;

	argcc(split);
	j = 0;
	while (split[j])
	{
		num = ft_atol(split[j]);
		if (num > 2147483647 || num < -2147483648)
		{
			write(2, "Error\n", 6);
			freesplit(split);
			free_stack(stack_a);
			exit(1);
		}
		node = ft_lstnew(num);
		node_back(stack_a, node);
		j++;
	}
}

void	parse_input(int argc, char **argv, int i, t_list **stack_a)
{
	char	**split;

	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split[0] || split[0][0] == '\0')
		{
			write(2, "Error\n", 6);
			freesplit(split);
			free_stack(stack_a);
			exit(1);
		}
		process_numbers(split, stack_a);
		freesplit(split);
		i++;
	}
}
