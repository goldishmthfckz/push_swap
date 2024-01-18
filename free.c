/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:41:29 by estegana          #+#    #+#             */
/*   Updated: 2024/01/12 15:41:31 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//freelist
//freestr

//free la liste a (en cas d'erreur ou de fin d'utilisation)
void	ft_freelist(t_list **a)
{
	t_list	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		(*a)->n = 0;
		free(*a);
		*a = tmp;
	}
}

//free une chaine de char
void	ft_freestr(char **av)
{
	char	*n;
	int		i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		n = av[i];
		i++;
		free(n);
	}
	av[i] = NULL;
}
