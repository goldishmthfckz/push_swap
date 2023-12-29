#include "../incl/push_swap.h"

//creer une node
pile	*createnode(int nb)
{
	pile *new;


	new = malloc(sizeof(pile));
	if (!new)
		write(1, "Error\n", 6);
	new->n = nb;
	new->next = NULL;
	return (new);
}

//ajouter une node a une pile
void	addback(pile **a, pile *new)
{
	if (!a)
		return ;
	if (!*a)
		*a = new;
	else
		(lastnode(*a))->next = new;

}

// creer une pile des arguments
pile	*createlist(int ac, char **av)
{
	pile *a;
	int i;
	int n;

	i = 1;
	if (ac < 2)
		write(1, "Error\n", 6);
	else
	{
		while (i < ac)
		{
			n = ft_atoi(av[i]);
			addback(&a, createnode(n));
			i++;
		}
	}
	return (a);
}

