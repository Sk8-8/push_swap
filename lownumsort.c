void	three(t_node *a)
{
	int	greater;

	greater = ;
	if((a)->index == greater)
		rotatenode(, 1);
	else if ((a)->next->index == greater)
		reverserotatenode(, 1);
	if ((a)->index > (*a)->next->index)
		swapfirstnode();
}

void five(t_node *a, t_node *b)
{
	int	size;

	size = nodecount(a);
	while (size --)
	{
		if ((a)->index == 0 || (a)->index == 1)
			pushnode(, 2);
		else
			rotatenode(, 1);
	}
	three(a);
	pushnode(, , 1);
	pushnode(, , 1);
	if ((a)->index > (a)->next->index)
		swapfirstnode();
}
