/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalmoma <abalmoma@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:10:46 by abalmoma          #+#    #+#             */
/*   Updated: 2026/11/23 21:55:12 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	argcc(char **argv)
{
	int	j;
	int	i;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_duplicates(t_list **stack_a)
{
	t_list	*current;
	t_list	*compare;

	if (!stack_a || !*stack_a)
		return ;
	current = *stack_a;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->content == compare->content)
			{
				write(2, "Error\n", 6);
				free_stack(stack_a);
				exit(1);
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

static int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_and_report(t_list **a, t_list **b, t_flags *flags)
{
	float	disorder;
	int		strategy;
	int		size;

	disorder = ft_disorder(a);
	size = ft_lstsize(*a);
	strategy = flags->strategy;
	if (strategy == STRATEGY_ADAPTIVE)
		strategy = ft_pick_strategy(disorder, size);
	if (!is_sorted(*a))
		ft_run_strategy(a, b, strategy);
	if (flags->bench)
		ft_print_bench(disorder, flags->strategy == STRATEGY_ADAPTIVE,
			strategy);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flags	flags;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		i = extract_simple_flags(argc, argv, &flags);
		if (i >= argc)
			return (write(2, "Error\n", 6), 1);
		parse_input(argc, argv, i, &stack_a);
		check_duplicates(&stack_a);
		sort_and_report(&stack_a, &stack_b, &flags);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
