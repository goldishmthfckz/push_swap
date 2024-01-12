/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:33:59 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:34:02 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//trie 3 nb
//1 si av[1] est le plus pti, on le met en 2nd (rra) et on swap
//2a si av[1] est le plu grand, on le met en dernier (ra)
//2b si c tjs pas trie, on swap
//3a si av[1] est le median et que le max est en 2nd, on rra
//3b si le max est deja en der, on swap
void	sort3(t_list **a)
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

//trie 4 nb
//ramene et pb le plu pti nb de la list a
//trier a contenant 3 nb;
//pa le plus ptit au dsu
void	sort4(t_list **a, t_list **b)
{
	int	i;

	i = imin(a);
	if (i == 1)
		ft_swap(a, 'a');
	else if (i == 2)
	{
		ft_rotate(a, 'a');
		ft_rotate(a, 'a');
	}
	else if (i == 3)
		ft_revrotate(a, 'a');
	ft_push(b, a, 'b');
	sort3(a);
	ft_push(a, b, 'a');
}

//trie 2 nb (sa), puis +
void	sort(t_list **a, t_list **b)
{
	if (ft_listlen(*a) == 2)
		ft_swap(a, 'a');
	if (ft_listlen(*a) == 3)
		sort3(a);
	if (ft_listlen(*a) == 4)
		sort4(a, b);
	if (ft_listlen(*a) == 5)
		printf("sort5 a faire\n");
	if (ft_listlen(*a) > 5)
		printf("sortbig a faire\n");
}
