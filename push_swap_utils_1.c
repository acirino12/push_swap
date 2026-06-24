#include "push_swap.h"


/**
 * Converte una stringa in un intero controllando la presenza di overflow.
 * Ritorna 1 in caso di successo, 0 se la stringa contiene caratteri errati o sfora INT.
 */
int	ft_atoi_save(const char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*result = (int)(num * sign);
	return (1);
}


void assign_indexes(t_stack *stack_a)
{
    t_node  *current;
    t_node  *compare;
    int     final_position;

    current = stack_a->top;
    while (current != NULL)
    {
        final_position = 0;
        compare = stack_a->top;
        
        // Confrontiamo il nodo attuale con tutti gli altri nodi dello stack
        while (compare != NULL)
        {
            // Se troviamo un numero più piccolo del nostro, 
            // significa che il nostro numero dovrà stare dopo di lui
            if (current->value > compare->value)
                final_position++;
            compare = compare->next;
        }
        
        // Assegniamo la posizione finale calcolata come indice del nodo
        current->index = final_position;
        current = current->next;
    }
}

int compute_disorder(t_stack *stack_a)
{
    t_node  *i;
    t_node  *j;
    int     mistakes;
    int     total_pairs;

    mistakes = 0;
    total_pairs = 0;
    if (!stack_a || stack_a->size < 2)
        return (0);
    i = stack_a->top;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            total_pairs += 1;
            if (i->index > j->index)
                mistakes += 1;
            j = j->next;
        }
        i = i->next;
    }
    if (total_pairs == 0)
        return (0);
    // Usiamo il casting a long per evitare overflow durante la moltiplicazione
    return ((int)(((long)mistakes * 10000) / total_pairs));
}
