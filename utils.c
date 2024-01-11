#include "push_swap.h"

//lastnode
//sorted
//ft_listlen

//nombre de la derniere node de la liste a
list	*lastnode(list *a)
{
	if (!a)
		return NULL;
	while (a->next)
		a = a->next;
	return a;
}

//liste a triee ou pas?
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

//longueur de la liste a
int	ft_listlen(list *a)
{
	int len;

	len = 0;
	while (a)
	{
		a = a->next;
		len++;
	}
	return (len);
}
