#include "push_swap.h"

//Funzione per far ruotare uno stack verso l'alto
//Il primo elemento divenata l'ultimo

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	//Se lo stack è vuoto o ha solo 1 elemento non c'è niente da ruotare
	if (!stack || stack->size < 2 || !stack->top)
		return ;
	first = stack->top;

	//1. Sposto la cima dello stack al secondo nodo
	stack->top = first->next;
	stack->top->prev = NULL;

	//2. Trovo l'ultimo nodo attuale
	last = stack->top;
	while (last->next)
		last = last->next;

	//3. Metto il nodo che prima stava in cima all'ultima posizione
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

// ra (rotate a) Sposta tutti gli elementi dello stack a verso l'alto di 1 posizione.
// Il primo elemento diventa l'ultimo

void	ra(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" ra: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	rotate(&ps->a);
	if (bench == 1)
		write(1, "ra\n", 3);
	ps->op_count++;
}

// rb (rotate b) Sposta tutti gli elementi dello stack b verso l'alto di 1 posizione.
// Il primo elemento diventa l'ultimo

void	rb(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" rb: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	rotate(&ps->b);
	if (bench == 1)
		write(1, "rb\n", 3);
	ps->op_count++;
}

// rr Esegue ra e rb contemporaneamente

void	rr(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" rr: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	rotate(&ps->a);
	rotate(&ps->b);
	if (bench == 1)
		write(1, "rr\n", 3);
	ps->op_count++;
}
