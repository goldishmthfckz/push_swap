#include "push_swap.h"

//creer une node a partir des argv
list *createnode(int nb)
{
	list *new;

	new = malloc(sizeof(list));
	if (!new)
		write(1, "Error\n", 1);
	new->n = nb;
	new->next = NULL;
	return (new);
}

//ajouter une node a la fin d'une list
void addback(list **a, list *new)
{
	if (!a)
		return ;
	if (!*a)
		*a = new;
	else
		(lastnode(*a)->next = new);
}

//generer une liste a partir d'arguments
list *createlist(int ac, char **av)
{
	list *a;
	int i;
	int nb;

	i = 1;
	a = NULL;
	if (ac < 2)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else
	{
		while (i < ac)
		{
			nb = ft_long_atoi(av[i]);
			addback(&a, createnode(nb));
			i++;
		}
	}
	return (a);
}
