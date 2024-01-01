/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:23:23 by estegana          #+#    #+#             */
/*   Updated: 2023/11/28 10:23:24 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/incl/libft.h"

typedef struct pile
{
	int	n;
	int i;
	struct pile *prev;
	struct pile	*next;
}	pile;

//createlist
pile	*createnode(int nb);
void	addback(pile **a, pile *new);
pile	*createlist(int ac, char **av);

//utils
pile	*lastnode(pile *list);

#endif
