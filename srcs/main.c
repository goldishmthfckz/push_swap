#include "../incl/push_swap.h"

int main(int ac, char **av)
{
	pile *a;

	a = createlist(ac, av);
	if (!a || error(a))
	{
		//free a
		write(1, "Error\n", 6);
	}
	if (!sorted(a))
		sort(&a);
	//free a mais pk?
	return (0);
}
