/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:29:34 by acirino           #+#    #+#             */
/*   Updated: 2026/06/27 15:57:08 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			strategy[2];
	int			bench;
	int			disorder;
	t_pushswap	*ps;

	ps = ft_calloc(1, sizeof(t_pushswap));
	if (!ps)
		return (1);
	parse_arguments(argc, argv, ps, strategy, &bench);
	assign_indexes(&ps->a);
	disorder = compute_disorder(&ps->a);
	if (strategy[0] == 0)
	{
		if (ps->a.size <= 15 || disorder < 2000)
			strategy[1] = 1;
		else if (ps->a.size >= 1500 || disorder >= 5000)
			strategy[1] = 3;
		else
			strategy[1] = 2;
	}
	if (strategy[0] == 1 || (strategy[0] == 0 && strategy[1] == 1))
		simple_sort(ps);
	else if (strategy[0] == 2 || (strategy[0] == 0 && strategy[1] == 2))
		medium_sort(ps);
	else if (strategy[0] == 3 || (strategy[0] == 0 && strategy[1] == 3))
		radix_sort(ps);
	bench_mode(bench, disorder, strategy, ps);
	free_stack(&ps->a);
	free (ps);
	return (0);
}
