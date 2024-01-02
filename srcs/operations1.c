#include "../incl/push_swap.h"

//sa, sb
//pa, pb
//ra, rb
//rra, rrb

void ft_swap(pile *a, char c)
{
	pile	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(pile **src, pile **dest, char c)
{
	pile	*newsrc;
	pile	*newdest;

	if (*dest != NULL)
	{
		newsrc = (*dest)->next;
		newdest = *src;
		*src = *dest;
		(*src)->next = newdest;
		*dest = newsrc;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(pile **a, char c)
{
	pile	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rev_rotate(pile **a, char c)
{
	pile	*new_tail;
	pile	*tail;
	pile	*before_tail;

	if (*a && (*a)->next)
	{
		tail = *a;
		before_tail = NULL;
		while (tail->next)
		{
			before_tail = tail;
			tail = tail->next;
		}
		new_tail = before_tail;
		if (new_tail)
		{
			new_tail->next = NULL;
			tail->next = *a;
			*a = tail;
		}
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
