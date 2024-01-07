#include "../incl/push_swap.h"

//n(ombre) de la derniere node
//tri ou pas
//taille de la pile
//i(ndex) du n(ombre) dans pile x

//renvoi de la derniere node
pile	*lastnode(pile *node)
{
	if (!node)
		return NULL;
	while (node->next)
		node = node->next;
	return (node);
}

//1 si triee, 0 sinon
int	sorted(pile *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (0);
		i = a->nbr;
		a = a->next;
	}
	return (1);
}

int	ft_pilelen(pile *a)
{
	size_t i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

//index du nombre n contenu dans la pile a
int	ipile(pile *a, int n)
{
	int i;

	i = 0;
	while (a->nbr != n)
	{
		i++;
		a = a->next;
	}
	a->i = 0;
	return (i);
}

