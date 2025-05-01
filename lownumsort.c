/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lownumsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:52:39 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/01 22:24:39 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_greater(t_node *a)
{
	int	max;

	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

void	three(t_node *a)
{
	int	greater;

	greater = get_greater(a);
	if (a->index == greater)
		rotatenode(&a, 1);
	else if (a->next->index == greater)
		reverserotatenode(&a, 1);
	if (a->index > a->next->index)
		swapfirstnode(a);
}

void	five(t_node **a, t_node **b, int argc)
{
	while (countnodes(*b) <= 1)
	{
		if ((*a)->index == 1 || (*a)->index == 2)
			pushnode(a, b, 2);
		else
			rotatenode(a, 1);
	}
	if ((*b)->index == 1)
		swap_b(*b);
	if (argc == 6)
	{
		if ((*a)->next->next->index != 5)
		{
			if ((*a)->index == 5)
				rotatenode(a, 1);
			else
				reverserotatenode(a, 1);
		}
	}
	if ((*a)->index > (*a)->next->index)
		swapfirstnode(*a);
	pushnode(a, b, 1);
	pushnode(a, b, 1);
}
