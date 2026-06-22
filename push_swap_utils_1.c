#include "push_swap.h"

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

int compute_disorder_with_index(t_stack *stack_a)
{
    t_node  *current;
    int     current_position;
    int     total_distance;
    int     max_possible_disorder;

    if (!stack_a || stack_a->size < 2)
        return (0);

    current = stack_a->top;
    current_position = 0;
    total_distance = 0;

    // 1. Calcoliamo la distanza accumulata di ogni nodo dalla sua posizione ideale
    while (current != NULL)
    {
        // Se la posizione attuale è diversa dall'indice finale, calcoliamo la differenza.
        // Usiamo il valore assoluto per sommare sempre distanze positive.
        if (current_position > current->index)
            total_distance += (current_position - current->index);
        else
            total_distance += (current->index - current_position);

        current_position++;
        current = current->next;
    }

    // 2. Formula matematica del massimo disordine teorico per questa dimensione (N)
    // Corrisponde alla massima distanza accumulabile se la lista fosse invertita.
    max_possible_disorder = (stack_a->size * stack_a->size) / 2;

    if (max_possible_disorder == 0)
        return (0);

    // 3. Trasformiamo in percentuale intera (0-100) moltiplicando prima di dividere
    return ((total_distance * 100) / max_possible_disorder);
}
