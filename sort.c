#include "push_swap.h"

//trie 3 nb
//si a[1] c le plus pti, rra et sa
//si a[1] c le plus grand, ra et si tjs pas triee, sa
//sinon
void	sort3(list **a)
{

	if (ft_min(*a) == (*a)->n)
	{
		ft_revrotate(a, 'a');
		ft_swap(a, 'a');
	}
	else if (ft_max(*a) == (*a)->n)
	{
		ft_rotate(a, 'a');
		if (!sorted(*a))
			ft_swap(a, 'a');
	}
	else
	{
		if (ilist(*a, ft_max(*a)) == 1)
			ft_revrotate(a, 'a');
		else
			ft_swap(a, 'a');
	}
}

void	sort(list **a)
{
	if (ft_listlen(*a) == 2)
		ft_swap(a, 'a');
	if (ft_listlen(*a) == 3)
		sort3(a);
}
