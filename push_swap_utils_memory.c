#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	print_error_and_exit(t_pushswap *ps)
{
	write(2, "Error\n", 6);
	if (ps)
	{
		free_stack(&ps->a);
		free_stack(&ps->b);
	}
	exit(1);
}
