#include "push_swap.h"

/**
 * Logica interna per far ruotare uno stack verso il basso.
 * L'ultimo elemento diventa il primo.
 */
static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	// Se lo stack è vuoto o ha meno di 2 elementi, non c'è nulla da ruotare
	if (!stack || stack->size < 2 || !stack->top)
		return ;
	// 1. Scorriamo la lista fino a trovare l'ultimo nodo
	last = stack->top;
	while (last->next)
		last = last->next;
	// 2. Scolleghiamo l'ultimo nodo dal penultimo
	if (last->prev)
		last->prev->next = NULL;
	// 3. Posizioniamo l'ultimo nodo sopra l'attuale cima
	last->next = stack->top;
	stack->top->prev = last;
	// 4. L'ultimo nodo diventa la nuova cima dello stack
	last->prev = NULL;
	stack->top = last;
}

/**
 * rra (reverse rotate a): Sposta tutti gli elementi dello stack a verso il basso di 1.
 * L'ultimo elemento diventa il primo.
 */
void	rra(t_pushswap *ps)
{
	reverse_rotate(&ps->a);
	write(1, "rra\n", 4);
	ps->op_count++;
}

/**
 * rrb (reverse rotate b): Sposta tutti gli elementi dello stack b verso il basso di 1.
 * L'ultimo elemento diventa il primo.
 */
void	rrb(t_pushswap *ps)
{
	reverse_rotate(&ps->b);
	write(1, "rrb\n", 4);
	ps->op_count++;
}

/**
 * rrr : Esegue rra e rrb contemporaneamente.
 */
void	rrr(t_pushswap *ps)
{
	reverse_rotate(&ps->a);
	reverse_rotate(&ps->b);
	write(1, "rrr\n", 4);
	ps->op_count++;
}
