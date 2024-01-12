/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftaajouteralibft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:33:06 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:09 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_long_atoi(char *str)
{
	int				sign;
	long long int	res;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
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
	if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
		ft_error();
	return (sign * res);
}
