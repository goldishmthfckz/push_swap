/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:55:39 by estegana          #+#    #+#             */
/*   Updated: 2024/01/20 16:55:40 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fait remonter le n de l'index en haut
void	inontop(t_list **a, int index, char c)
{
	if (index <= ft_listlen(*a) / 2)
	{
		while (index > 0)
		{
			if (c == 'a')
				ft_rotate(a, 'a');
			else if (c == 'b')
				ft_rotate(a, 'b');
			index--;
		}
	}
	else
	{
		while (index < ft_listlen(*a))
		{
			if (c == 'a')
				ft_revrotate(a, 'a');
			else if (c == 'b')
				ft_revrotate(a, 'b');
			index++;
		}
	}
}

//
void	move_elem(t_list **a, t_list **b, t_list **c)
{
	int		nb_min;
	int		i;
	int		target;
	t_list	*tmp;

	nb_min = (*c)->cost;
	i = (*c)->index;
	target = (*c)->index_maj;
	tmp = *c;
	while (tmp)
	{
		if (tmp->cost <= nb_min)
		{
			nb_min = tmp->cost;
			i = tmp->index;
			target = tmp->index_maj;
		}
		tmp = tmp->next;
	}
	inontop(b, i, 'b');
	inontop(a, target, 'a');
}

//trouve l'index du plus petit n dla liste et le monte en index 0
void	lastsort(t_list **a)
{
	int		index;

	index = ilist(*a, ft_min(*a));
	inontop(a, index, 'a');
}
