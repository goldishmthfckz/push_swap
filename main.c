/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:32:46 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:32:49 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = createlist(ac, av);
	b = NULL;
	if (!a || !nodoublons(a))
	{
		ft_freelist(&a);
		ft_error();
	}
	if (!sorted(a))
		sort(&a, &b);
	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
	ft_freelist(&a);
	return (0);
}
