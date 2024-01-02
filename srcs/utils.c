#include "../incl/push_swap.h"

//derniere node
//tri ou pas???
//

//renvoi de la derniere node
pile	*lastnode(pile *list)
{
	if (!list)
		return NULL;
	while (list->next)
		list = list->next;
	return (list);
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
