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
	int	index;
	int	coups;
	struct list	*next;
}	list;

//createlist
list	*createnode(int nb);
void	addback(list **a, list *new);
list	*createlist(int ac, char **av);

//parsing
int	nodoublons(char **av);
int	noalpha(char **av);
int	nottoolong(char **av);
int	parsing(char **av);

//sort
void	sort3(list **a);
void	sort(list **a);

//utils
list	*lastnode(list *a);
int	sorted(list *a);
int	ft_listlen(list *a);
void	ft_free(list **a);
int	ft_min(list *a);
int	ft_max(list *a);
int	ilist(list *a, int nb);

//operations 1
void	ft_swap(list **a, char c);
void	ft_ss(list **a, list **b);
void ft_push(list **dst, list **src, char c);
void	ft_rotate(list **a, char c);
void	ft_rr(list **a, list **b);
void	ft_revrotate(list **a, char c);
void	ft_rrr(list **a, list **b);

//autres
int	ft_long_atoi(char *str);

#endif
