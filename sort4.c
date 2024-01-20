#include "push_swap.h"

void	move_stack_b(t_list **begin_b, int index)
{
	if (index <= ft_listlen(*begin_b) / 2)
	{
		while (index > 0)
		{
			ft_rotate(begin_b, 'b');
			index--;
		}
	}
	else
	{
		while (index < ft_listlen(*begin_b))
		{
			ft_revrotate(begin_b, 'b');
			index++;
		}
	}
}

void	move_stack_a(t_list **begin_a, int index_maj)
{
	if (index_maj <= ft_listlen(*begin_a) / 2)
	{
		while (index_maj > 0)
		{
			ft_rotate(begin_a, 'a');
			index_maj--;
		}
	}
	else
	{
		while (index_maj < ft_listlen(*begin_a))
		{
			ft_revrotate(begin_a, 'a');
			index_maj++;
		}
	}
}

void	move_elem(t_list **begin_a, t_list **begin_b, t_list **list)
{
	int		nb_min;
	int		i;
	int		maj;
	t_list	*begin;

	nb_min = (*list)->cost;
	i = (*list)->index;
	maj = (*list)->index_maj;
	begin = *list;
	while (begin)
	{
		if (begin->cost <= nb_min)
		{
			nb_min = begin->cost;
			i = begin->index;
			maj = begin->index_maj;
		}
		begin = begin->next;
	}
	move_stack_b(begin_b, i);
	move_stack_a(begin_a, maj);
}

int	index_in_list(t_list **begin_list, int nb)
{
	int		i;
	t_list	*list;

	i = 0;
	list = *begin_list;
	while (list)
	{
		if (list->n == nb)
			return (i);
		list = list->next;
		i++;
	}
	return (-1);
}

void	last_rotation(t_list **begin_a)
{
	int		min;
	int		index;
	t_list	*begin;

	min = (*begin_a)->n;
	begin = *begin_a;
	while (begin)
	{
		if (begin->n < min)
			min = begin->n;
		begin = begin->next;
	}
	index = index_in_list(begin_a, min);
	move_stack_a(begin_a, index);
}
