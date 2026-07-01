/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoppo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:03:09 by marcoppo          #+#    #+#             */
/*   Updated: 2026/07/01 11:03:12 by marcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
}

void	sa(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" sa: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	swap(&ps->a);
	if (bench == 1)
		write(1, "sa\n", 3);
	ps->op_count++;
}

void	sb(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" sb: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	swap(&ps->b);
	if (bench == 1)
		write(1, "sb\n", 3);
	ps->op_count++;
}

void	ss(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" ss: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	swap(&ps->a);
	swap(&ps->b);
	if (bench == 1)
		write(1, "ss\n", 3);
	ps->op_count++;
}
