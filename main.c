#include "push_swap.h"

int main(int ac, char **av)
{
	list *a;

	a = createlist(ac, av);
	if (!a || !parsing(av))
	{
		//free a
		write(1, "Error\n", 6);
	}
	if (!sorted(a))
		write(1,"i:\n", 3);
	//free a car on en a plus besoin
	return (0);
}
