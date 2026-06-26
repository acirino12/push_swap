#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

/* Struttura per il singolo nodo della lista doppiamente concatenata */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* Struttura per la gestione dello stack */
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* Struttura principale del programma */
typedef struct s_pushswap
{
	t_stack	a;
	t_stack	b;
	int		op_count;
}	t_pushswap;

/* ========================================================================== */
/*                               PROTOTIPI                                    */
/* ========================================================================== */

/* Utility e Inizializzazione - si trovano su utils_1 */
void	assign_indexes(t_stack *stack_a);
int		compute_disorder(t_stack *stack_a);
int		ft_atoi_save(const char *str, int *result);

/* Operazioni Base (Istruzioni di Push_swap) */
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

/* Gestione Memoria ed Errori */
void	free_stack(t_stack *stack);
void	free_matrix(char **matrix);
void	print_error_and_exit(t_pushswap *ps);

/* Prototipi aggiunti presenti in parsing */
void    parse_arguments(int argc, char **argv, t_pushswap *ps, int *strategy, int *bench);


// Algoritmi di Ordinamento
void	bubble_sort(t_pushswap *ps);
void	medium_sort(t_pushswap *ps);
void	radix_sort(t_pushswap *ps);

#endif
