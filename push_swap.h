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

typedef struct list
{
	int			n;
	int			index;
	int			coups;
	struct list	*next;
}				t_list;

//createlist
t_list	*createnode(int nb);
void	addback(t_list **a, t_list *new);
t_list	*quotationmarks(char **av);
t_list	*createlist(int ac, char **av);

//parsing
int		nodoublons(t_list *a);

//sort 1
void	sort3(t_list **a);
void	sort4(t_list **a, t_list **b);
void	minontop_presort5(t_list **a);
void	sort5(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b);
//sort 2
void	sortfinal(t_list **a, t_list **b);

//utils 1
t_list	*lastnode(t_list *a);
int		sorted(t_list *a);
int		ft_listlen(t_list *a);
void	ft_freelist(t_list **a);
void	ft_freestr(char **av);
void	ft_error(void);

//utils 2
int		ft_min(t_list *a);
int		ft_max(t_list *a);
int		ilist(t_list *a, int nb);
int		imin(t_list **a);

//operations 1
void	ft_swap(t_list **a, char c);
void	ft_push(t_list **dst, t_list **src, char c);
void	ft_rotate(t_list **a, char c);
void	ft_revrotate(t_list **a, char c);
//operations 2
void	ft_ss(t_list **a, t_list **b);
void	ft_rr(t_list **a, t_list **b);
void	ft_rrr(t_list **a, t_list **b);

//autres
int		ft_long_atoi(char *str);

#endif
