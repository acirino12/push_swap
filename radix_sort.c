/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:28:54 by acirino           #+#    #+#             */
/*   Updated: 2026/06/29 17:29:46 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void process_a(t_pushswap *ps, int size_a, int bucket)
{
    while (size_a--)
    {
        if ((ps->a.top->index & bucket) == 0)
            ra(ps, 1);
        else
            pb(ps, 1);
    }
}

static void process_b(t_pushswap *ps, int size_b, int bucket)
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

void    radix_sort(t_pushswap *ps)
{
    int bucket;
    int total_size;

    if (compute_disorder(&ps->a) == 0)
        return ;
    total_size = ps->a.size;
    bucket = 1;
    while (bucket < total_size)
    {
        process_a(ps, ps->a.size, bucket);
        process_b(ps, ps->b.size, bucket);
        bucket *= 2;
    }
    while (ps->b.size > 0)
    {
        rrb(ps, 1);
        pa(ps, 1);
        ra(ps, 1);
    }
}