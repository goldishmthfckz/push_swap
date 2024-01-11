#include "push_swap.h"

void	ft_swap(list **a, char c)
{
	list	*tmp;

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

void	ft_ss(list **a, list **b)
{
	ft_swap(a, 's');
	ft_swap(b, 's');
	write(1, "ss\n", 3);
}

void	ft_push(list **dst, list **src, char c)
{
	list	*newsrc;
	list	*newdst;

	if (*src != NULL)
	{
		newsrc = (*src)->next;
		newdst = *dst;
		*dst = *src;
		(*dst)->next = newdst;
		*src = newsrc;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(list **a, char c)
{
	list	*tmp;

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

void	ft_rr(list **a, list **b)
{
	ft_rotate(a, 'r');
	ft_rotate(b, 'r');
	write(1, "rr\n", 3);
}

void	ft_revrotate(list **a, char c)
{
	list	*newlastnode;
	list	*lastnode;
	list	*beforelastnode;

	if (*a && (*a)->next)
	{
		lastnode = *a;
		beforelastnode = NULL;
		while (lastnode->next)
		{
			beforelastnode = lastnode;
			lastnode = lastnode->next;
		}
		newlastnode = beforelastnode;
		if (newlastnode)
		{
			newlastnode->next = NULL;
			lastnode->next = *a;
			*a = lastnode;
		}
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rrr(list **a, list **b)
{
	ft_revrotate(a, 'r');
	ft_revrotate(b, 'r');
	write(1, "rrr\n", 4);
}
