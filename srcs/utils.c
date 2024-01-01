#include "../incl/push_swap.h"

//renvoi de la derniere node
pile	*lastnode(pile *list)
{
	if (!list)
		return NULL;
	while (list->next)
		list = list->next;
	return (list);
}
