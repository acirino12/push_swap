#include "push_swap.h"
#include <limits.h>

// Ritorna 1 in caso di successo, 0 in caso di errore (caratteri errati o overflow)
int ft_atoi_save(const char *str, int *result)
{
    long    num;
    int     sign;
    int     i;

    num = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i]) // Stringa vuota o solo un segno "+" o "-"
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '10') // Verifica caratteri validi
            return (0);
        num = num * 10 + (str[i] - '0');
        // Controllo overflow immediato durante il ciclo
        if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
            return (0);
        i++;
    }
    *result = (int)(num * sign);
    return (1);
}

int has_duplicate(t_stack *stack_a, int value)
{
    t_node  *current;

    if (!stack_a || !stack_a->top)
        return (0);
    current = stack_a->top;
    while (current != NULL)
    {
        if (current->value == value)
            return (1); // Duplicato trovato
        current = current->next;
    }
    return (0);
}

int push_back(t_stack *stack_a, int value)
{
    t_node  *new_node;
    t_node  *last;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->value = value;
    new_node->index = -1; // L'indice verrà calcolato successivamente
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

void free_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *next_node;

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

// Ricorda di modificare per gestire l'aggiunta di ft_split nel caso in cui i numeri ricevuti in argomento siano racchiusi da virgolette (es.: "1 2 3")

int parse_arguments(int argc, char **argv, t_stack *stack_a)
{
    int i;
    int value;

    i = 1; // Partiamo da 1 per saltare il nome dell'eseguibile
    while (i < argc)
    {
        // 1. Controlla caratteri ed overflow
        if (!ft_atoi_save(argv[i], &value))
        {
            write(2, "Error\n", 6);
            free_stack(stack_a);
            exit(1);
        }
        // 2. Controlla i duplicati
        if (has_duplicate(stack_a, value))
        {
            write(2, "Error\n", 6);
            free_stack(stack_a);
            exit(1);
        }
        // 3. Inserisci nello stack
        if (!push_back(stack_a, value))
        {
            write(2, "Error\n", 6);
            free_stack(stack_a);
            exit(1);
        }
        i++;
    }
    return (1);
}
