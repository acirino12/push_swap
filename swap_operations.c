#include "push_swap.h"

/**
 * Logica interna per scambiare i primi due nodi di uno stack.
 * Aggiorna correttamente tutti i puntatori next e prev della lista.
 */
static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	// Aggiorna il legame tra il primo nodo e quello che diventerà il terzo
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	// Inverto il legame tra primo e secondo nodo
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	// Il secondo nodo diventa la nuova cima dello stack
	stack->top = second;
}

//swap nello stack a
void	sa(t_pushswap *ps)
{
	swap(&ps->a);
	write(1, "sa\n", 3);
	ps->op_count++;
}

//swap nello stack b
void	sb(t_pushswap *ps)
{
	swap(&ps->b);
	write(1, "sb\n", 3);
	ps->op_count++;
}

//swap in tutti gli stack allo stesso tempo
void	ss(t_pushswap *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	write(1, "ss\n", 3);
	ps->op_count++;
}
