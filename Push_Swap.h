/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:37:44 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/23 22:36:50 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define STRATEGY_ADAPTIVE 0
# define STRATEGY_SIMPLE 1
# define STRATEGY_MEDIUM 2
# define STRATEGY_COMPLEX 3

typedef struct s_flags
{
	int	strategy;
	int	bench;
}		t_flags;

float	ft_disorder(t_list **stack);

int		extract_simple_flags(int argc, char **argv, t_flags *flags);
int		do_swap(t_list **stack);
int		do_rotate(t_list **stack);
int		do_reverse_rotate(t_list **stack);
int		ft_pick_strategy(float disorder, int size);
int		*ft_get_counts(void);

char	**ft_split(char const *s, char c);
char	**ft_get_names(void);

void	ft_run_strategy(t_list **a, t_list **b, int strategy);
void	ft_print_op(char *op);
void	ft_print_bench(float disorder, int adaptive, int strategy);
void	process_numbers(char **split, t_list **stack_a);
void	ft_adaptive(t_list **stack_a, t_list **stack_b);
void	freesplit(char **splitarr);
void	parse_input(int argc, char **argv, int i, t_list **stack_a);
void	assign_index(t_list *stack);
void	radix_sort(t_list **a, t_list **b);
void	ft_chunked_sort(t_list **stack_a, t_list **stack_b);
void	ft_selection_sort(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);
void	check_duplicates(t_list **stack_a);
void	node_back(t_list **head, t_list *new_node);
void	argcc(char **argv);
void	check(char **argv);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_a(t_list **stack_a);
void	ft_reverse_rotate_b(t_list **stack_b);
void	ft_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_swap_a_and_b(t_list **stack_a, t_list **stack_b);
void	ft_swap_a(t_list **stack_a);
void	ft_swap_b(t_list **stack_b);

#endif
