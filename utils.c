#include "push_swap.h"

//lastnode
//sorted
//ft_listlen
//freelist
//ft_min
//ft_max
//ilist

//renvoie le nombre de la derniere node de la liste a
list	*lastnode(list *a)
{
	if (!a)
		return NULL;
	while (a->next)
		a = a->next;
	return a;
}

//liste a triee ou pas? 1 si oui, sinon 0
int	sorted(list *a)
{
	int nb;

	nb = a->n;
	while (a)
	{
		if (nb > a->n)
			return 0;
		nb = a->n;
		a = a->next;
	}
	return (1);
}

//renvoie la longueur len de la liste a
int	ft_listlen(list *a)
{
	int i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

//free la liste a (en cas d'erreur ou de fin d'utilisation)
void	ft_free(list **a)
{
	list	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		(*a)->n = 0;
		free(*a);
		*a = tmp;
	}
}

//renvoie le plus pti nombre dla liste a
int	ft_min(list *a)
{
	int i;
	i = a->n;
	while (a)
	{
		if (i > a->n)
			i = a->n;
		a = a->next;
	}
	return (i);
}

//renvoie le plus grand nombre de la liste a
int	ft_max(list *a)
{
	int i;

	i = a->n;
	while (a)
	{
		if (i < a->n)
			i = a->n;
		a = a->next;
	}
	return (i);
}

//renvoie l'index du nombre n ds la list a
int	ilist(list *a, int nb)
{
	int i;

	i = 0;
	while (a->n != nb)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
