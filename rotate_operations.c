/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoppo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:55:42 by marcoppo          #+#    #+#             */
/*   Updated: 2026/07/01 10:55:44 by marcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2 || !stack->top)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" ra: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	rotate(&ps->a);
	if (bench == 1)
		write(1, "ra\n", 3);
	ps->op_count++;
}

void	rb(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" rb: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	rotate(&ps->b);
	if (bench == 1)
		write(1, "rb\n", 3);
	ps->op_count++;
}

void	rr(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" rr: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	rotate(&ps->a);
	rotate(&ps->b);
	if (bench == 1)
		write(1, "rr\n", 3);
	ps->op_count++;
}
