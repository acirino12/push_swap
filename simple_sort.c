/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:32:55 by acirino           #+#    #+#             */
/*   Updated: 2026/06/29 17:42:13 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_node *s, int target_index)
{
	int		pos;

	pos = 0;
	while (s)
	{
		if (s->index == target_index)
			return (pos);
		pos++;
		s = s->next;
	}
	return (0);
}

static void	sort_three(t_pushswap *ps)
{
	t_stack	*a;

	a = &ps->a;
	if (a->size > 2)
	{
		if (a->top->index > a->top->next->index
			&& a->top->index > a->top->next->next->index)
			ra(ps, 1);
		else if (a->top->next->index > a->top->index
			&& a->top->next->index > a->top->next->next->index)
			rra(ps, 1);
	}
	if (a->size > 1)
	{
		if (a->top->index > a->top->next->index)
			sa(ps, 1);
	}
}

void	simple_sort(t_pushswap	*ps)
{
	int		i;

	if (compute_disorder(&ps->a) == 0)
		return ;
	i = 0;
	while (ps->a.size > 3)
	{
		if (get_position(ps->a.top, i) < ps->a.size / 2)
		{
			while (ps->a.top->index != i)
				ra(ps, 1);
		}
		else
		{
			while (ps->a.top->index != i)
				rra(ps, 1);
		}
		pb(ps, 1);
		i++;
	}
	sort_three(ps);
	while (ps->b.size)
		pa(ps, 1);
}
