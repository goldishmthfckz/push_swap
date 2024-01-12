/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:57:55 by estegana          #+#    #+#             */
/*   Updated: 2023/05/17 18:53:29 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_isalnum(int c)
{
	if ((c <= 122 && c >= 97) || (c <= 90 && c >= 65) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}
