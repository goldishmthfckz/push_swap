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
// # include "../libft/incl/libft.h"

typedef struct list
{
	int	n;
	int i;
	struct list *prev;
	struct list	*next;
}	list;

//createlist
list	*createnode(int nb);
void	addback(list **a, list *new);
list	*createlist(int ac, char **av);

//error
int	nodoublons(char **av);
int	noalpha(char **av);
int	nottoolong(char **av);
int	parsing(char **av);

//utils
list	*lastnode(list *a);
int	sorted(list *a);

//autres
int	ft_long_atoi(char *str);

#endif