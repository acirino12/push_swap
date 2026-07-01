/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:29:37 by acirino           #+#    #+#             */
/*   Updated: 2026/06/29 17:42:38 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk * 2);
}

static void	empty_b_to_a(t_pushswap *ps)
{
	while (ps->b.size > 0)
	{
		if (get_position(ps->b.top, ps->b.size - 1) < ps->b.size / 2)
			while (ps->b.top->index != ps->b.size - 1)
				rb(ps, 1);
		else
			while (ps->b.top->index != ps->b.size - 1)
				rrb(ps, 1);
		pa(ps, 1);
	}
}

void	medium_sort(t_pushswap *ps)
{
	int	i;
	int	chunk_size;

	if (compute_disorder(&ps->a) == 0)
		return ;
	i = 0;
	chunk_size = calculate_chunk(ps->a.size);
	while (ps->a.size > 0)
	{
		if (ps->a.top->index <= i + chunk_size)
		{
			pb(ps, 1);
			if (ps->b.top->index <= i)
				rb(ps, 1);
			i++;
		}
		else
			ra(ps, 1);
	}
	empty_b_to_a(ps);
}
