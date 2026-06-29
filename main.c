/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:29:34 by acirino           #+#    #+#             */
/*   Updated: 2026/06/29 16:40:46 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_mode(int *strategy, int disorder)
{
	if (disorder < 2000)
		strategy[1] = 1;
	else if (disorder >= 5000)
		strategy[1] = 3;
	else
		strategy[1] = 2;
}

int	main(int argc, char **argv)
{
	int			strategy[3];
	int			disorder;
	t_pushswap	*ps;

	ps = ft_calloc(1, sizeof(t_pushswap));
	if (!ps)
		return (1);
	parse_arguments(argc, argv, ps, strategy);
	assign_indexes(&ps->a);
	disorder = compute_disorder(&ps->a);
	if (strategy[0] == 0)
		adaptive_mode(strategy, disorder);
	if (strategy[0] == 1 || (strategy[0] == 0 && strategy[1] == 1))
		simple_sort(ps);
	else if (strategy[0] == 2 || (strategy[0] == 0 && strategy[1] == 2))
		medium_sort(ps);
	else if (strategy[0] == 3 || (strategy[0] == 0 && strategy[1] == 3))
		radix_sort(ps);
	bench_mode(strategy[2], disorder, strategy, ps);
	free_stack(&ps->a);
	free_stack(&ps->b);
	free (ps);
	return (0);
}
