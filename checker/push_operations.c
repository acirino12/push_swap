#include "checker.h"

// Logica per spostare il nodo dallo stack src allo tsack dest

static void	push(t_stack *dest, t_stack *src)
{
	t_node	*node_to_move;

	if (!src || src->size == 0 || !src->top)
		return ;
	//1. Sgancio il nodo dallo stack sorgente
	node_to_move = src->top;
	src->top = node_to_move->next;
	if (src->top)
		src->top->prev = NULL;
	src->size--;
	//2. Inserisco il nodo appena sganciato in cima allo stack destinazione
	node_to_move->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_move;
	dest->top = node_to_move;
	dest->size++;
}

//pa (push a) prende il primo elemento in cima a b e lo mette in cima ad a
//Non fa nulla se b è vuoto

void	pa(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" pa: ", 2);
		ft_putnbr_fd(count, 2);
		return ;
	}
	count++;
	push(&ps->a, &ps->b);
	write(1, "pa\n", 3);
	ps->op_count++;
}

//pb (push b) prende il primo elemento in cima ad a e lo mette in cima a b
//Non fa nulla se a è vuoto

void	pb(t_pushswap *ps, int bench)
{
	static int	count = 0;

	if(bench == 0)
	{
		ft_putstr_fd(" pb: ", 2);
		ft_putnbr_fd(count, 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	count++;
	push(&ps->b, &ps->a);
	write(1, "pb\n", 3);
	ps->op_count++;
}
