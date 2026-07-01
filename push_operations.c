/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoppo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:12:37 by marcoppo          #+#    #+#             */
/*   Updated: 2026/07/01 10:12:40 by marcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	t_node	*node_to_move;

	if (!src || src->size == 0 || !src->top)
		return ;
	node_to_move = src->top;
	src->top = node_to_move->next;
	if (src->top)
		src->top->prev = NULL;
	src->size--;
	node_to_move->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_move;
	dest->top = node_to_move;
	dest->size++;
}

void	pa(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" pa: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	push(&ps->a, &ps->b);
	if (bench == 1)
		write(1, "pa\n", 3);
	ps->op_count++;
}

void	pb(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" pb: ", 2);
		ft_putnbr_fd(count, 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	count++;
	push(&ps->b, &ps->a);
	if (bench == 1)
		write(1, "pb\n", 3);
	ps->op_count++;
}
