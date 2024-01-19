/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:54:07 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:54:08 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_min
//ft_max
//ilist
//imin
//

//plus pti nombre dla liste a
int	ft_min(t_list *a)
{
	int	i;

	i = a->n;
	while (a)
	{
		if (i > a->n)
			i = a->n;
		a = a->next;
	}
	return (i);
}

//plus grand nombre de la liste a
int	ft_max(t_list *a)
{
	int	i;

	i = a->n;
	while (a)
	{
		if (i < a->n)
			i = a->n;
		a = a->next;
	}
	return (i);
}

//index du nombre n ds la list a
int	ilist(t_list *a, int nb)
{
	int	i;

	i = 0;
	while (a->n != nb)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

//index du nombre le plu pti dla list a
int	imin(t_list **a)
{
	int		min;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	min = ft_min(tmp);
	while (tmp->n != min)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

//reinitialise les index de la liste a
void	reinitindex(t_list **a)
{
	t_list	*tmp;
	int	i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		printf("n = %d, i = %i\n", tmp->n, tmp->index);
		i++;
		tmp = tmp->next;
	}
}
