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

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/incl/libft.h"

typedef struct list
{
	int			n;
	int			index;
	int			cost;
	int			index_maj;
	struct list	*target;
	struct list	*next;
}				t_list;

//createlist
t_list		*createnode(int nb);
void		addback(t_list **a, t_list *new);
t_list		*createlist2(char **av);
long int	ft_long_atoi(char *str);
t_list		*createlist(int ac, char **av);

//free
void		ft_freelist(t_list **a);
void		ft_freestr(char **av);

//operations 1
void		ft_swap(t_list **a, char c);
void		ft_push(t_list **dst, t_list **src, char c);
void		ft_rotate(t_list **a, char c);
void		ft_revrotate(t_list **a, char c);
//operations 2
void		ft_ss(t_list **a, t_list **b);
void		ft_rr(t_list **a, t_list **b);
void		ft_rrr(t_list **a, t_list **b);

//parsing
int			nodouble(t_list *a);

//sort 1
void		sort3(t_list **a);
void		sort4(t_list **a, t_list **b);
void		minontop_presort5(t_list **a);
void		sort5(t_list **a, t_list **b);
void		sort(t_list **a, t_list **b);
//sort 2
int			*sort_int_tab(t_list **begin_a, int *tab);
void		create_sort_tab(t_list **begin_a, int *tab);
int			find_max(int *tab, int len);
void		keep_just_max(t_list **begin_a, t_list **begin_b, int *tab);
void		sort5plus(t_list **a, t_list **b);
//sort 3
t_list		*ft_reinitstruct(int i, int maj, int move);
int			ft_list_push_back_stock(t_list **a, int i, int maj, int move);
int			index_maj(t_list **a, int nb, int max);
int			count_move(t_list **begin_a, t_list **begin_b, int index, int maj);
int			create_list(t_list **a, t_list **begin_b, t_list **list, int max);
//sort4
void		reinitb(t_list **b, int index);
void		reinita(t_list **a, int index_maj);
void		move_elem(t_list **a, t_list **b, t_list **list);
int			index_in_list(t_list **a, int nb);
void		last_rotation(t_list **a);

//utils 1
t_list		*lastnode(t_list *a);
int			sorted(t_list *a);
int			ft_listlen(t_list *a);
void		ft_error(void);
//utils 2
int			ft_min(t_list *a);
int			ft_max(t_list *a);
int			ilist(t_list *a, int nb);
int			imin(t_list **a);

#endif
