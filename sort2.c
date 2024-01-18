/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:53:53 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:53:54 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

////attribue index aux nbs dla list a ds ordre croissant
void	initindex(t_list **a)
{
	int i;
	t_list *tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

void	sortindex(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (a)
	{
		if ((*a)->n > (*a)->next->n)
		{
			tmp->index = (*a)->index;
			(*a)->index = tmp->next->index;
			(*a)->next->index = tmp->index;
		}
		else
			(*a) = (*a)->next;
	}
}


void	sort5plus(t_list **a, t_list **b)
{
	t_list *tmp;
	int	imed;

	imed = ft_listlen(*a) / 2;
	initindex(a);
	sortindex(a);
	printf("imed = %i\n", imed);
	while (ft_listlen(*a) > 5)
	{
		ft_push(b, a, 'b');
		if ((*b)->index < imed)
			ft_rotate(b, 'b');
	}
	tmp = *b;
	while (tmp)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}
