/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:32:55 by acirino           #+#    #+#             */
/*   Updated: 2026/06/27 15:28:29 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Returns the distance of index=target_value from the node(=top of the stack)
	We'll use this value to decide whether to rotate or reverse-rotate
*/
static int	get_position(t_node *s, int target_index)
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

/*
To sort three elements:
	Put the max in last position:
		if max in position 1       -> ra
		else if max in posizione 2 -> rra
	Control the first two elements
*/

static void	sort_three(t_pushswap *ps)
{
    t_stack *a = &ps->a;
    
	if (a->size > 2)
	{
    	if (a->top->index > a->top->next->index && a->top->index > a->top->next->next->index)
        	ra(ps, 1);
    	else if (a->top->next->index > a->top->index && a->top->next->index > a->top->next->next->index)
        	rra(ps, 1);
	}
	if (a->size > 1)
	{
    	if (a->top->index > a->top->next->index)
        	sa(ps, 1);
	}
}

/*
	Take the minimus index of stack a and put it on stack b.
	Do this till stack a has 3 elements.
*/

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

/**
 * Algoritmo Medio: Chunk/Sandglass Sort. Complessità O(n rad(n)).
 * Spinge i nodi in B divisi per blocchi dinamici e li riprende in modo ottimizzato.
 */
void	medium_sort(t_pushswap *ps)
{
	int	i;
	int	chunk_size;

	if (compute_disorder(&ps->a) == 0)
		return ;
	i = 0;
	// Dimensione ottimale del chunk approssimata a √n
	chunk_size = 1;
	while (chunk_size * chunk_size < ps->a.size)
		chunk_size++;
	chunk_size *= 2; // Moltiplicatore empirico per ottimizzare il numero di mosse
	// Fase 1: Spinta condizionata in B
	while (ps->a.size > 0)
	{
		if (ps->a.top->index <= i)
		{
			pb(ps, 1);
			rb(ps, 1); // Ruota in fondo i più piccoli per creare la clessidra
			i++;
		}
		else if (ps->a.top->index <= i + chunk_size)
		{
			pb(ps, 1);
			i++;
		}
		else
			ra(ps, 1);
	}
	// Fase 2: Svuotamento controllato di B verso A
	while (ps->b.size > 0)
	{
		if (get_position(ps->b.top, ps->b.size - 1) < ps->b.size / 2)
		{
			while (ps->b.top->index != ps->b.size - 1)
				rb(ps, 1);
		}
		else
		{
			while (ps->b.top->index != ps->b.size - 1)
				rrb(ps, 1);
		}
		pa(ps, 1);
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
		while (size[0]--)
		{
			if ((ps->a.top->index & bucket) == 0)
				ra(ps, 1);
			else
				pb(ps, 1);
		}
		while (size[1]--)
		{
			rrb(ps, 1);
			if ((ps->b.top->index & bucket) == 0)
			{
				pa(ps, 1);
				ra(ps, 1);
			}
		}
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
