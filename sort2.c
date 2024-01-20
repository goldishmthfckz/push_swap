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

int	*sort_int_tab(t_list **begin_a, int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < ft_listlen(*begin_a))
	{
		j = i + 1;
		while (j < ft_listlen(*begin_a))
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				j = i + 1;
			}
			else
				j++;
		}
		i++;
	}
	return (tab);
}

void	create_sort_tab(t_list **begin_a, int *tab)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *begin_a;
	while (tmp)
	{
		tab[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	tab = sort_int_tab(begin_a, tab);
}

int	find_max(int *tab, int len)
{
	int	i;
	int	max;

	i = 1;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

void	keep_just_max(t_list **begin_a, t_list **begin_b, int *tab)
{
	int	max;
	int	compteur;
	int	len;

	len = ft_listlen(*begin_a);
	max = find_max(tab, len);
	compteur = -1;
	while (++compteur < len)
	{
		if ((*begin_a)->n != max)
		{
			ft_push(begin_b, begin_a, 'b');
			if ((*begin_b)->n >= tab[(len) / 2])
				ft_rotate(begin_b, 'b');
		}
		else
			ft_rotate(begin_a, 'a');
	}
}

void	sort5plus(t_list **a, t_list **b)
{
	int		*tab;
	int		max;
	t_list	*list;

	tab = malloc(sizeof(int) * ft_listlen(*a));
	if (!tab)
		return ;
	create_sort_tab(a, tab);
	keep_just_max(a, b, tab);
	free(tab);
	max = (*a)->n;
	while (*b)
	{
		list = NULL;
		if (!create_list(a, b, &list, max))
			break ;
		move_elem(a, b, &list);
		ft_push(a, b, 'a');
		ft_freelist(&list);
	}
	last_rotation(a);
}
