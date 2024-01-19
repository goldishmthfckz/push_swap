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


int	*ft_sort_int_tab(t_list **a, int *tab)
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

int	ft_median(t_list **a, int *tab)
{
	t_list	*tmp;
	int		i;
	int		imed;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tab[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	tab = ft_sort_int_tab(a, tab);
	imed = ft_listlen(*a) / 2;
	printf("chiffre median : %d\n", tab[imed]);
	return (tab[imed]);
}

void	firstpb(t_list **a, t_list **b, int *tab)
{
	int imed;

	imed = ft_median(a, tab);
		while (ft_listlen(*a) > 5)
	{
		if ((*a)->n < imed)
		{
			ft_push(b, a, 'b');
			ft_rotate(b, 'b');
		}
		else
			ft_push(b, a, 'b');
	}
	sort5(a, b);
}

//void	ft_target()
//{

//}

//int	ft_cost(t_list *a)
//{

//}

void	sort5plus(t_list **a, t_list **b)
{
	int	*tab;
	t_list *tmpb;
	t_list *tmpa;

	tab = malloc(sizeof(int) * ft_listlen(*a));
	if (!tab)
		return ;
	firstpb(a, b, tab);
	free(tab);
	reinitindex(a);
	reinitindex(b);
	tmpb = *b;
	printf("--------- liste b ----------\n");
	while (tmpb)
	{
		printf("%d\n", tmpb->n);
		tmpb = tmpb->next;
	}
	tmpa = *a;
	printf("--------- liste a ----------\n");
	while (tmpa)
	{
		printf("%d\n", tmpa->n);
		tmpa = tmpa->next;
	}
}
