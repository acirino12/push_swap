/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:32:55 by acirino           #+#    #+#             */
/*   Updated: 2026/06/25 10:38:56 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_pushswap	*ps)
{
	t_stack	*a;
	int		i;

	a = &ps->a;
	while (compute_disorder(a))
	{
		i = 0;
		while (i < a->size)
		{
			if (i != a->size -1 && a->top->index > a->top->next->index)
				sa(ps);
			ra(ps);
			i++;
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

	bucket = 1;
	set_size(size, ps);
	while (bucket < size[0] + size[1])
	{
		while (size[0]--)
		{
			if ((ps->a.top->index & bucket) == 0)
				ra(ps);
			else
				pb(ps);
		}
		while (size[1]--)
		{
			rrb(ps);
			if ((ps->b.top->index & bucket) == 0)
			{
				pa(ps);
				ra(ps);
			}
		}
		bucket *= 2;
		set_size(size, ps);
	}
	while (size[1]--)
		{
			if (size[1] > 1)
				rrb(ps);
			pa(ps);
			ra(ps);
		}
}