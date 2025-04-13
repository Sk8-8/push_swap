/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:58 by kguillem          #+#    #+#             */
/*   Updated: 2025/04/13 17:27:35 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	indextab(int *tab, int val)
{
	int	i;

	i = 0;
	while (tab && tab[i] != val)
		i ++;
	return (i + 1);
}

void	bubblesort(int *tab, t_node *tmp)
{
	while (tmp)
	{
		tmp->index = indextab(tab, tmp->val);
		tmp = tmp->next;
	}
}

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	bubblesortindex(t_node *stack)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		*tab;

	tab = malloc(sizeof(int) * countnodes(stack));
	if (!tab)
		error();
	i = -1;
	tmp = stack;
	while (tmp && tab)
	{
		tab[++i] = tmp->val;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < countnodes(stack) && tab)
	{
		j = -1;
		while (++j < countnodes(stack) - 1)
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
	}
	bubblesort(tab, stack);
	free(tab);
}
