/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:29:34 by acirino           #+#    #+#             */
/*   Updated: 2026/06/27 17:26:26 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_pushswap	*ps;
	char		*buffer;
	
	ps = ft_calloc(1, sizeof(t_pushswap));
	if (!ps)
		return (1);
	parse_arguments_checker(argc, argv, ps);
	while ((buffer = get_next_line(0)))
	{
		execute(buffer, ps);
		free(buffer);
	}
	if (compute_disorder(&ps->a) == 0 && ps->b.size == 0)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	free_stack(&ps->a);
	free (ps);
	return (0);
}

void	execute(char *buffer, t_pushswap *ps)
{
	if (ft_strncmp(buffer, "sa\n", 3))
		sa(ps, 1);
	else if (ft_strncmp(buffer, "sb\n", 3))
		sb(ps, 1);
	else if (ft_strncmp(buffer, "ss\n", 3))
		ss(ps, 1);
	else if (ft_strncmp(buffer, "pa\n", 3))
		pa(ps, 1);
	else if (ft_strncmp(buffer, "pb\n", 3))
		pb(ps, 1);
	else if (ft_strncmp(buffer, "ra\n", 3))
		ra(ps, 1);
	else if (ft_strncmp(buffer, "rb\n", 3))
		rb(ps, 1);
	else if (ft_strncmp(buffer, "rr\n", 3))
		rr(ps, 1);
	else if (ft_strncmp(buffer, "rra\n", 4))
		rra(ps, 1);
	else if (ft_strncmp(buffer, "rrb\n", 4))
		rrb(ps, 1);
	else if (ft_strncmp(buffer, "rrr\n", 4))
		rrr(ps, 1); 
	else
		handle_parse_error(ps, NULL);
}

void	parse_arguments_checker(int argc, char **argv, t_pushswap *ps)
{
	int		i;
	int		j;
	int		value;
	char	**split_args;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == 0)
			handle_parse_error(ps, NULL);
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			handle_parse_error(ps, NULL);
		j = 0;
		while (split_args[j])
		{
			if (!ft_atoi_save(split_args[j], &value)
				|| has_duplicate(&ps->a, value)
				|| !push_back(&ps->a, value))
				handle_parse_error(ps, split_args);
			j++;
		}
		free_matrix(split_args);
		i++;
	}
}
