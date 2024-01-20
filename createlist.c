/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:32:32 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:32:36 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//long atoi

//creer une node a partir des argv
t_list	*createnode(int nb)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->n = nb;
	new->next = NULL;
	return (new);
}

//ajouter une node a la fin d'une list
void	addback(t_list **a, t_list *new)
{
	if (!a)
		return ;
	if (!*a)
		*a = new;
	else
		(lastnode(*a)->next = new);
}

//gerer le cas ou les av sont entre guillemets
t_list	*createlist2(char **av)
{
	t_list	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(av[1], ' ');
	while (tmp[i])
	{
		j = ft_long_atoi(tmp[i]);
		addback(&a, createnode(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

//generer une liste a partir d'arguments
t_list	*createlist(int ac, char **av)
{
	t_list	*a;
	int		i;
	int		nb;

	i = 1;
	a = NULL;
	if (ac < 2)
		exit(1);
	if (ac == 2)
		a = createlist2(av);
	else
	{
		while (i < ac)
		{
			nb = ft_long_atoi(av[i]);
			addback(&a, createnode(nb));
			i++;
		}
	}
	return (a);
}
