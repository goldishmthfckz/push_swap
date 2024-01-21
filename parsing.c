/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:33:36 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:39 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nodouble(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->n == tmp->n)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

int	noalpha(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '-' && (av[i][j] < '0' || av[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	nolong(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_long_atoi(av[i]) < -2147483648)
			return (0);
		else if (ft_long_atoi(av[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

