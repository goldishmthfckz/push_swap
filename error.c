#include "../incl/push_swap.h"

//checker s'il y a des doublons
int	doublons(pile *a)
{
	pile *tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->n == tmp->n)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
