/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:15:16 by marcoppo          #+#    #+#             */
/*   Updated: 2026/07/07 10:31:26 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

/* Structure for a single node in a doubly linked list */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* Structure for stack management */
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* Structure for the main program */
typedef struct s_pushswap
{
	t_stack	a;
	t_stack	b;
	int		op_count;
}	t_pushswap;

/* ========================================================================== */
/*                               PROTOTYPES                                    */
/* ========================================================================== */

void	bench_mode(int bench, int disorder, int *strategy, t_pushswap *ps);

/* Utility and Initialization - located in utils_1 */
void	assign_indexes(t_stack *stack_a);
int		compute_disorder(t_stack *stack_a);
int		ft_atoi_save(const char *str, int *result);
void	handle_parse_error(t_pushswap *ps, char **matrix);

/* Operations */
// Swap
void	sa(t_pushswap *ps, int bench);
void	sb(t_pushswap *ps, int bench);
void	ss(t_pushswap *ps, int bench);

// Push
void	pa(t_pushswap *ps, int bench);
void	pb(t_pushswap *ps, int bench);

// Rotate
void	ra(t_pushswap *ps, int bench);
void	rb(t_pushswap *ps, int bench);
void	rr(t_pushswap *ps, int bench);

// Reverse Rotate
void	rra(t_pushswap *ps, int bench);
void	rrb(t_pushswap *ps, int bench);
void	rrr(t_pushswap *ps, int bench);

/* Memory and Error Handling */
void	free_stack(t_stack *stack);
void	free_matrix(char **matrix);
void	print_error_and_exit(t_pushswap *ps);

/* Parsing */
void	parse_arguments(int argc, char **argv, t_pushswap *ps, int *strategy);
int		has_duplicate(t_stack *stack, int value);
int		push_back(t_stack *stack, int value);

// Sorting Algorithms and utility functions
void	simple_sort(t_pushswap *ps);
void	medium_sort(t_pushswap *ps);
void	radix_sort(t_pushswap *ps);
int		get_position(t_node *s, int target_index);

#endif
