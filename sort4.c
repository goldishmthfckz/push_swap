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

void	reinitb(t_list **b, int index)
{
	if (index <= ft_listlen(*b) / 2)
	{
		while (index > 0)
		{
			ft_rotate(b, 'b');
			index--;
		}
	}
	else
	{
		while (index < ft_listlen(*b))
		{
			ft_revrotate(b, 'b');
			index++;
		}
	}
}

void	reinita(t_list **a, int index_maj)
{
	if (index_maj <= ft_listlen(*a) / 2)
	{
		while (index_maj > 0)
		{
			ft_rotate(a, 'a');
			index_maj--;
		}
	}
	else
	{
		while (index_maj < ft_listlen(*a))
		{
			ft_revrotate(a, 'a');
			index_maj++;
		}
	}
}

void	move_elem(t_list **a, t_list **b, t_list **list)
{
	int		nb_min;
	int		i;
	int		maj;
	t_list	*tmp;

	nb_min = (*list)->cost;
	i = (*list)->index;
	maj = (*list)->index_maj;
	tmp = *list;
	while (tmp)
	{
		if (tmp->cost <= nb_min)
		{
			nb_min = tmp->cost;
			i = tmp->index;
			maj = tmp->index_maj;
		}
		tmp = tmp->next;
	}
	reinitb(b, i);
	reinita(a, maj);
}

void	last_rotation(t_list **a)
{
	int		min;
	int		index;
	t_list	*tmp;

	min = (*a)->n;
	tmp = *a;
	while (tmp)
	{
		if (tmp->n < min)
			min = tmp->n;
		tmp = tmp->next;
	}
	index = ilist(*a, min);
	reinita(a, index);
}
