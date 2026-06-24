#include "push_swap.h"

int main(int argc, char **argv)
{
	int			strategy;
	int			disorder;
	t_pushswap	*ps;

	ps = NULL;
	parse_arguments(argc, argv, ps, &strategy);
	assign_indexes(&ps->a);
	disorder = compute_disorder(&ps->a);
	if (strategy == 0)
	{
		if (disorder < 2000)
			strategy = 1;
		else if (disorder > 6500)
			strategy = 3;
		else
			strategy = 2;
	}
	
	// Stampiamo i passi dell'algoritmo scelto 
		
}
