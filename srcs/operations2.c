#include "../incl/push_swap.h"

//ss
//rr
//rrr

void	ft_sswap(t_stack **a, t_stack **b)
{
	ft_swap(a, 's');
	ft_swap(b, 's');
	write(1, "ss\n", 3);
}

void	ft_rrotate(t_stack **a, t_stack **b)
{
	ft_rotate(a, 'r');
	ft_rotate(b, 'r');
	write(1, "rr\n", 3);
}

void	ft_rrev_rotate(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a, 'r');
	ft_rev_rotate(b, 'r');
	write(1, "rrr\n", 4);
}
