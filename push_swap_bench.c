/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bech.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:57:14 by acirino           #+#    #+#             */
/*   Updated: 2026/06/27 16:01:43 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bench_mode_2(int* strategy, t_pushswap *ps);

void	bench_mode(int bench, int disorder, int* strategy, t_pushswap *ps)
{
	if (bench == 0)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(disorder/100, 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(disorder - (disorder/100)*100, 2);
	if (disorder - (disorder/100)*100 == 0)
		ft_putnbr_fd(0, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	if (strategy[0] == 0)
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (strategy[1] == 1)
			ft_putstr_fd("O(n^2)", 2);
		else if (strategy[1] == 2)
			ft_putstr_fd("O(n rad(n))", 2);
		else
			ft_putstr_fd("O(n log(n))", 2);
	}
	bench_mode_2(strategy, ps);
}

static void	bench_mode_2(int* strategy, t_pushswap *ps)
{
	if (strategy[0] == 1)
			ft_putstr_fd("Simple / O(n^2)", 2);
	else if (strategy[0] == 2)
			ft_putstr_fd("Medium / O(n rad(n))", 2);
	else if (strategy[0] == 3)
			ft_putstr_fd("Complex / O(n log(n))", 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(ps->op_count, 2);
	ft_putstr_fd("\n[bench]", 2);
	sa(ps, 0);
	sb(ps, 0);
	ss(ps, 0);
	pa(ps, 0);
	pb(ps, 0);
	ft_putstr_fd("[bench]", 2);
	ra(ps, 0);
	rb(ps, 0);
	rr(ps, 0);
	rra(ps, 0);
	rrb(ps, 0);
	rrr(ps, 0);
}
