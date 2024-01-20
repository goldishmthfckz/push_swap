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

t_list	*ft_reinitstruct(int i, int maj, int move)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->index = i;
	elem->index_maj = maj;
	elem->cost = move;
	elem->next = NULL;
	return (elem);
}

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

int	index_maj(t_list **a, int nb, int max)
{
	t_list	*begin;
	int		index;
	int		maj;

	begin = *a;
	maj = max;
	while (begin)
	{
		if (begin->n > nb && begin->n < maj)
			maj = begin->n;
		begin = begin->next;
	}
	index = 0;
	begin = *a;
	while (begin)
	{
		if (begin->n == maj)
			return (index);
		begin = begin->next;
		index++;
	}
	return (index);
}

int	count_move(t_list **a, t_list **b, int index, int maj)
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

int	create_list(t_list **a, t_list **b, t_list **list, int max)
{
	int		index;
	int		maj;
	int		move;
	t_list	*begin;

	begin = *b;
	index = 0;
	while (begin)
	{
		maj = index_maj(a, begin->n, max);
		move = count_move(a, b, index, maj);
		if (!(ft_list_push_back_stock(list, index, maj, move)))
		{
			ft_freelist(list);
			return (0);
		}
		begin = begin->next;
		index++;
	}
	return (1);
}
