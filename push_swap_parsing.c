#include "push_swap.h"

/**
 * Gestisce l'errore di parsing stampando "Error" su stderr,
 * liberando la memoria attiva e terminando il programma.
 */
void	handle_parse_error(t_pushswap *ps, char **matrix)
{
	write(2, "Error\n", 6);
	if (matrix)
		free_matrix(matrix);
	if (ps)
	{
		free_stack(&ps->a);
		free_stack(&ps->b);
		free(ps);
	}
	exit(1);
}

/**
 * Verifica se un valore è già presente all'interno dello stack A.
 * Ritorna 1 se duplicato, 0 altrimenti.
 */
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

/**
 * Alloca e inserisce un nuovo nodo in coda allo stack A.
 * Ritorna 1 in caso di successo, 0 se la malloc fallisce.
 */
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

/**
 * Riconosce i flag dei selettori di strategia definiti dal soggetto.
 * Utilizza la tua ft_strncmp della libft per i controlli.
 */
static int	strategy_selector(char *s, int *strategy)
{
	if (ft_strncmp(s, "--adaptive", 11) == 0)
		*strategy = 0;
	else if (ft_strncmp(s, "--simple", 9) == 0)
		*strategy = 1;
	else if (ft_strncmp(s, "--medium", 9) == 0)
		*strategy = 2;
	else if (ft_strncmp(s, "--complex", 10) == 0)
		*strategy = 3;
	else
		return (0);
	return (1);
}

static int	bench_selector(char *s, int *bench)
{
	*bench = 0;
	if (ft_strncmp(s, "--bench", 8) == 0)
		*bench = 1;
	else
		return (0);
	return (1);
}

/**
 * Funzione principale per il parsing. Legge l'array degli argomenti,
 * estrae le sotto-stringhe tramite ft_split e popola in modo sicuro lo stack.
 */
void	parse_arguments(int argc, char **argv, t_pushswap *ps, int *strategy, int *bench)
{
	int		i;
	int		j;
	int		value;
	char	**split_args;

	i = 1;
	*strategy = 0;
	if (argc > i && bench_selector(argv[i], bench))
		i++;
	if (argc > i && strategy_selector(argv[i], strategy))
		i++;
	while (i < argc)
	{
		if (argv[i][0] == 0)
			handle_parse_error(ps, NULL);
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			handle_parse_error(ps, NULL);
		j = 0;
		while (split_args[j])
		{
			if (!ft_atoi_save(split_args[j], &value)
				|| has_duplicate(&ps->a, value)
				|| !push_back(&ps->a, value))
				handle_parse_error(ps, split_args);
			j++;
		}
		free_matrix(split_args);
		i++;
	}
}
