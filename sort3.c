/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:55:50 by estegana          #+#    #+#             */
/*   Updated: 2024/01/20 16:55:51 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reattribue les infos a un noeud
t_list	*ft_reinitstruct(int i, int maj, int move)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->index = i;
	node->index_maj = maj;
	node->cost = move;
	node->next = NULL;
	return (node);
}

//
int	ft_list_push_back_stock(t_list **a, int i, int maj, int move)
{
	t_list	*list;

	list = *a;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_reinitstruct(i, maj, move);
		if (!(list->next))
			return (0);
	}
	else
	{
		*a = ft_reinitstruct(i, maj, move);
		if (!(*a))
			return (0);
	}
	return (1);
}

//trouve la target de n ds la list a puis renvoie son index
int	itarget(t_list **a, int nb, int max)
{
	t_list	*tmp;
	int		index;
	int		target;

	tmp = *a;
	target = max;
	while (tmp)
	{
		if (tmp->n > nb && tmp->n < target)
			target = tmp->n;
		tmp = tmp->next;
	}
	index = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->n == target)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	ft_cost(t_list **a, t_list **b, int index, int maj)
{
	int	nb;

	nb = 0;
	if (index > ft_listlen(*b) / 2)
		nb += ft_listlen(*b) - index;
	else
		nb += index;
	if (maj > ft_listlen(*a) / 2)
		nb += ft_listlen(*a) - maj;
	else
		nb += maj;
	return (nb);
}

int	remainb(t_list **a, t_list **b, t_list **list, int max)
{
	int		index;
	int		target;
	int		move;
	t_list	*tmp;

	tmp = *b;
	index = 0;
	while (tmp)
	{
		target = itarget(a, tmp->n, max);
		move = ft_cost(a, b, index, target);
		if (!(ft_list_push_back_stock(list, index, target, move)))
		{
			ft_freelist(list);
			return (0);
		}
		tmp = tmp->next;
		index++;
	}
	return (1);
}
