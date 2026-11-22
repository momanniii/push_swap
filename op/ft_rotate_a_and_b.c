/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_and_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 19:36:42 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/14 21:23:00 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	do_rotate(stack_a);
	do_rotate(stack_b);
	ft_print_op("rr");
}
