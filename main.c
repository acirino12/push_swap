/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:29:34 by acirino           #+#    #+#             */
/*   Updated: 2026/06/25 10:29:52 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int			strategy;
	int			disorder;
	t_pushswap	*ps;

	ps = ft_calloc(1, sizeof(t_pushswap));
	if (!ps)
		return (1);
	parse_arguments(argc, argv, ps, &strategy);
	assign_indexes(&ps->a);
	disorder = compute_disorder(&ps->a);
	if (strategy == 0)
	{
		if (disorder < 2000)
			strategy = 1;
		else if (disorder > 6500)
			strategy = 3;
		else
			strategy = 2;
	}
	if (strategy == 1)
		bubble_sort(ps);
//	else if (strategy == 2)
	else if (strategy == 3)
		radix_sort(ps);
	free_stack(&ps->a);
	free (ps);
	return (0);
}
