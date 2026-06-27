#include "checker.h"

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
void	sa(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" sa: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	swap(&ps->a);
	ps->op_count++;
	
}

//swap nello stack b
void	sb(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" sb: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	swap(&ps->b);
	ps->op_count++;
}

//swap in tutti gli stack allo stesso tempo
void	ss(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" ss: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	swap(&ps->a);
	swap(&ps->b);
	ps->op_count++;
}
