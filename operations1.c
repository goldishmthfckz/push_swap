/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:33:18 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:24 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **a, char c)
{
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(t_list **dst, t_list **src, char c)
{
	t_list	*newsrc;
	t_list	*newdst;

	if (*src != NULL)
	{
		newsrc = (*src)->next;
		newdst = *dst;
		*dst = *src;
		(*dst)->next = newdst;
		*src = newsrc;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_list **a, char c)
{
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_revrotate(t_list **a, char c)
{
	t_list	*newlastnode;
	t_list	*lastnode;
	t_list	*beforenode;

	if (*a && (*a)->next)
	{
		lastnode = *a;
		beforenode = NULL;
		while (lastnode->next)
		{
			beforenode = lastnode;
			lastnode = lastnode->next;
		}
		newlastnode = beforenode;
		if (newlastnode)
		{
			newlastnode->next = NULL;
			lastnode->next = *a;
			*a = lastnode;
		}
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
