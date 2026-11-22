/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 21:27:07 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/14 21:27:11 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	set_flag(char *arg, t_flags *flags)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		flags->strategy = STRATEGY_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		flags->strategy = STRATEGY_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		flags->strategy = STRATEGY_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		flags->strategy = STRATEGY_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		flags->bench = 1;
	else
		return (0);
	return (1);
}

int	extract_simple_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	i = 1;
	flags->strategy = STRATEGY_ADAPTIVE;
	flags->bench = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!set_flag(argv[i], flags))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (i);
}
