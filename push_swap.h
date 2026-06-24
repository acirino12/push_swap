#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

/* Operazioni Base (Istruzioni di Push_swap) */
// Swap
void	sa(t_pushswap *ps);
void	sb(t_pushswap *ps);
void	ss(t_pushswap *ps);

// Push
void	pa(t_pushswap *ps);
void	pb(t_pushswap *ps);

// Rotate
void	ra(t_pushswap *ps);
void	rb(t_pushswap *ps);
void	rr(t_pushswap *ps);

// Reverse Rotate
void	rra(t_pushswap *ps);
void	rrb(t_pushswap *ps);
void	rrr(t_pushswap *ps);

/* Gestione Memoria ed Errori */
void	free_stack(t_stack *stack);
void	free_matrix(char **matrix); //Questa funzione si trova nel parsing
void	print_error_and_exit(t_pushswap *ps);

/* Prototipi aggiunti presenti in parsing */
void    parse_arguments(int argc, char **argv, t_pushswap *ps, int *strategy);
int     strategy_selector(char *s, int *strategy);
int     ft_atoi_save(const char *str, int *result);
int     has_duplicate(t_stack *stack_a, int value);
int     push_back(t_stack *stack_a, int value);

#endif
