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

//ordonne ds ordre croiss le tab d'int
int	*sort_int_tab(t_list **a, int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < ft_listlen(*a))
	{
		j = i + 1;
		while (j < ft_listlen(*a))
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

//convertit la liste a en tableau d'int
//puis la trie ac ftsortiinttab
void	sorttab(t_list **a, int *tab)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tab[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	tab = sort_int_tab(a, tab);
}

//pb tt sauf le max de a
//si le n pushed > que la mediane b, rb
void	pbtilmaxa(t_list **a, t_list **b, int *tab)
{
	int	max;
	int	i;
	int	len;

	len = ft_listlen(*a);
	max = ft_max(*a);
	i = -1;
	while (++i < len)
	{
		if ((*a)->n != max)
		{
			ft_push(b, a, 'b');
			if ((*b)->n >= tab[(len) / 2])
				ft_rotate(b, 'b');
		}
		else
			ft_rotate(a, 'a');
	}
}

//
void	sort5plus(t_list **a, t_list **b)
{
	int		*tab;
	int		max;
	t_list	*tmp;

	tab = malloc(sizeof(int) * ft_listlen(*a));
	if (!tab)
		return ;
	sorttab(a, tab);
	pbtilmaxa(a, b, tab);
	free(tab);
	max = (*a)->n;
	while (*b)
	{
		tmp = NULL;
		if (!create_list(a, b, &tmp, max))
			break ;
		move_elem(a, b, &tmp);
		ft_push(a, b, 'a');
		ft_freelist(&tmp);
	}
	lastsort(a);
}

//afficher les listes
//tmpa = *a;
//printf("------- a -------------\n");
//while (tmpa)
//{
//	printf("%d\n", tmpa->n);
//	tmpa = tmpa->next;
//}
//tmpb = *b;
//printf("------- b -------------\n");
//while (tmpb)
//{
//	printf("%d\n", tmpb->n);
//	tmpb = tmpb->next;
//}
