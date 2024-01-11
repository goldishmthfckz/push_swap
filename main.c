#include "push_swap.h"

int main(int ac, char **av)
{
	list *a;

	if (!parsing(av))
		printf("Error (parsing)");
	a = createlist(ac, av);
	if (!a)
	{
		ft_free(&a);
		printf("Error (probleme avec a");
	}
	//while(a)
	//{
	//	printf("%i\n", a->n);
	//	a = a->next;
	//}
	if (!sorted(a))
	{
		printf("pas triee, instructions:\n");
		sort(&a);
	}
	ft_free(&a);
	return (0);
}
