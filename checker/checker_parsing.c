#include "checker.h"

void	handle_parse_error(t_pushswap *ps, char **matrix)
{
	write(2, "Error\n", 6);
	if (matrix)
		free_matrix(matrix);
	free_stack(&ps->a);
	exit(1);
}

int	has_duplicate(t_stack *stack_a, int value)
{
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (0);
	current = stack_a->top;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	push_back(t_stack *stack_a, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	if (!stack_a->top)
	{
		new_node->prev = NULL;
		stack_a->top = new_node;
	}
	else
	{
		last = stack_a->top;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	stack_a->size++;
	return (1);
}
