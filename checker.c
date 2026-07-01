/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoppo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:03:20 by marcoppo          #+#    #+#             */
/*   Updated: 2026/07/01 10:05:05 by marcoppo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_stack_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	if (stack_b && stack_b->size > 0)
		return (0);
	if (!stack_a || !stack_a->top)
		return (1);
	current = stack_a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	execute_op(char *line, t_pushswap *ps)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(ps, 2);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(ps, 2);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(ps, 2);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(ps, 2);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(ps, 2);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(ps, 2);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(ps, 2);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(ps, 2);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(ps, 2);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(ps, 2);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(ps, 2);
	else
		return (0);
	return (1);
}

static char	*read_line_stdin(void)
{
	char	*buffer;
	char	c;
	int		i;
	int		bytes;

	buffer = malloc(5);
	if (!buffer)
		return (NULL);
	i = 0;
	bytes = read(0, &c, 1);
	while (bytes > 0)
	{
		buffer[i++] = c;
		if (c == '\n' || i >= 4)
			break ;
		bytes = read(0, &c, 1);
	}
	buffer[i] = '\0';
	if (i == 0 && bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

int	main(int argc, char **argv)
{
	t_pushswap	*ps;
	char		*line;
	int			dummy_strat[3];

	if (argc < 2)
		return (0);
	ps = ft_calloc(1, sizeof(t_pushswap));
	if (!ps || (parse_arguments(argc, argv, ps, dummy_strat), 0))
		return (1);
	line = read_line_stdin();
	while (line)
	{
		if (!execute_op(line, ps))
			(free(line), print_error_and_exit(ps));
		free(line);
		line = read_line_stdin();
	}
	if (is_stack_sorted(&ps->a, &ps->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&ps->a), free_stack(&ps->b), free(ps), 0);
}
