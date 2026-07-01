/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:28:54 by acirino           #+#    #+#             */
/*   Updated: 2026/06/29 17:48:22 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_a(t_pushswap *ps, int size_a, int bucket)
{
	while (size_a--)
	{
		if ((ps->a.top->index & bucket) == 0)
			ra(ps, 1);
		else
			pb(ps, 1);
	}
}

static void	process_b(t_pushswap *ps, int size_b, int bucket)
{
	while (size_b--)
	{
		rrb(ps, 1);
		if ((ps->b.top->index & bucket) == 0)
		{
			pa(ps, 1);
			ra(ps, 1);
		}
	}
}

static void	set_size(int *size, t_pushswap *ps)
{
	size[0] = (&ps->a)->size;
	size[1] = (&ps->b)->size;
}

void	radix_sort(t_pushswap *ps)
{
	int	bucket;
	int	size[2];

	if (compute_disorder(&ps->a) == 0)
		return ;
	bucket = 1;
	set_size(size, ps);
	while (bucket < size[0] + size[1])
	{
		process_a(ps, size[0], bucket);
		process_b(ps, size[1], bucket);
		bucket *= 2;
		set_size(size, ps);
	}
	while (size[1]--)
	{
		rrb(ps, 1);
		pa(ps, 1);
		ra(ps, 1);
	}
}
