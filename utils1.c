/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:34:07 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:34:09 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//lastnode
//sorted
//ft_listlen
//ft_error
//longatoi

//long atoi
long int	ft_long_atoi(char *str)
{
	int				sign;
	long long int	res;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		ft_error();
	return (sign * res);
}

//nombre de la derniere node de la liste a
t_list	*lastnode(t_list *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

//1 si liste triee, sinon 0
int	sorted(t_list *a)
{
	int	nb;

	nb = a->n;
	while (a)
	{
		if (nb > a->n)
			return (0);
		nb = a->n;
		a = a->next;
	}
	return (1);
}

//longueur len de la liste a
int	ft_listlen(t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

//affiche "Error et fini le programme"
void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

