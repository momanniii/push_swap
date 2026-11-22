/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a_and_b.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:23:08 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/14 21:22:52 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	do_reverse_rotate(stack_a);
	do_reverse_rotate(stack_b);
	ft_print_op("rrr");
}
