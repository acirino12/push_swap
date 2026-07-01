/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoppo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:55:04 by marcoppo          #+#    #+#             */
/*   Updated: 2026/07/01 10:55:06 by marcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2 || !stack->top)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	last->prev = NULL;
	stack->top = last;
}

void	rra(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" rra: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	reverse_rotate(&ps->a);
	if (bench == 1)
		write(1, "rra\n", 4);
	ps->op_count++;
}

void	rrb(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" rrb: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	reverse_rotate(&ps->b);
	if (bench == 1)
		write(1, "rrb\n", 4);
	ps->op_count++;
}

void	rrr(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if (bench == 0)
	{
		ft_putstr_fd(" rrr: ", 2);
		ft_putnbr_fd(count, 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	count++;
	reverse_rotate(&ps->a);
	reverse_rotate(&ps->b);
	if (bench == 1)
		write(1, "rrr\n", 4);
	ps->op_count++;
}
