/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:32:55 by acirino           #+#    #+#             */
/*   Updated: 2026/06/25 11:56:48 by acirino          ###   ########.fr       */
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
				sa(ps, 1);
			ra(ps, 1);
			i++;
		}
	}
}

static void	set_size(int *size, t_pushswap *ps)
{
	size[0] = (&ps->a)->size;
	size[1] = (&ps->b)->size;
}

/**
 * Trova la posizione (indice di nodo) del valore cercato nello stack B.
 * Serve per calcolare se conviene fare rb o rrb.
 */
static int	get_pos_in_b(t_stack *b, int target_index)
{
	t_node	*curr;
	int		pos;

	curr = b->top;
	pos = 0;
	while (curr)
	{
		if (curr->index == target_index)
			return (pos);
		pos++;
		curr = curr->next;
	}
	return (0);
}

/**
 * Algoritmo Medio: Chunk/Sandglass Sort. Complessità O(n rad(n)).
 * Spinge i nodi in B divisi per blocchi dinamici e li riprende in modo ottimizzato.
 */
void	medium_sort(t_pushswap *ps)
{
	int	i;
	int	chunk_size;

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
		if (get_pos_in_b(&ps->b, ps->b.size - 1) < ps->b.size / 2)
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
