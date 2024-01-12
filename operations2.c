/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:35:26 by estegana          #+#    #+#             */
/*   Updated: 2024/01/11 17:35:28 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a, 's');
	ft_swap(b, 's');
	write(1, "ss\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a, 'r');
	ft_rotate(b, 'r');
	write(1, "rr\n", 3);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_revrotate(a, 'x');
	ft_revrotate(b, 'x');
	write(1, "rrr\n", 4);
}
