/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:41:59 by kguillem          #+#    #+#             */
/*   Updated: 2025/02/12 21:42:04 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortedcheck(t_node *a)
{
	while (a->next)
	{
		if (a->next->val < a->val)
			return (0);
		a = a->next;
	}
	return (1);
}

void	radix(t_node **a, t_node **b, int i)
{
	int	n;
	int	ptr;

	n = countnodes(*a);
	while (n != 0)
	{
		ptr = (*a)->index;
		if (!(ptr & (1 << i)))
			pushnode(a, b, 2);
		else
			rotatenode(a,1);
		n --;
	}
	while (*b)
		pushnode(a, b, 1);
}

void	sort(t_node **a)
{
	t_node	*b;
	int			i;

	b = NULL;
	i = 0;
	while (!sortedcheck(*a))
	{
		radix(a, &b, i);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;

	a = NULL;
	if (argc < 2)
		return (0);
	checkerror(argc, argv);
	filllist(&a, argc, argv);
	bubblesortindex(a);
	sort(&a);
	freelist(&a);
	return (0);
}
