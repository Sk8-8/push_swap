#include "push_swap.h"

int	get_greater(t_node *a)
{
	int max;

	max = a->val;
	while (a)
	{
		if (a->val > max)
			max = a->val;
		a = a->next;
	}
	return (max);
}

void	three(t_node *a)
{
	int	greater;

	greater = get_greater(a);
	if((a)->index == greater)
		rotatenode(a, 1);
	else if ((a)->next->index == greater)
		reverserotatenode(a, 1);
	if ((a)->index > (*a)->next->index)
		swapfirstnode(a);
}

void five(t_node **a, t_node **b)
{
	int	size;

	size = countnodes(*a);
	while (size --)
	{
		if ((a)->index == 0 || (a)->index == 1)
			pushnode(a, b, 2);
		else
			rotatenode(a, 1);
	}
	three(a);
	pushnode(a, b, 1);
	pushnode(a, b, 1);
	if ((a)->index > (a)->next->index)
		swapfirstnode(*a);
}
