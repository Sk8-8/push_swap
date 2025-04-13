/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:15 by kguillem          #+#    #+#             */
/*   Updated: 2025/04/13 22:36:10 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapfirstnode(t_node *a)
{
	int	tmp;

	tmp = a->val;
	a->val = a->next->val;
	a->next->val = tmp;
	ft_printf("sa\n");
}

void	pushnode(t_node **a, t_node **b, int state)
{
	t_node	*tmp;

	if (state == 1)
	{
		if (countnodes(*b) == 0)
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		ft_printf("pa\n");
	}
	else if (state == 2)
	{
		if (*a == NULL)
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		ft_printf("pb\n");
	}
}

void	rotatenode(t_node **a, int state)
{
	t_node	*first;
	t_node	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (state == 1)
		ft_printf("ra\n");
	else if (state == 2)
		ft_printf("rb\n");
}

void	reverserotatenode(t_node **a, int state)
{
	t_node	*tmp;
	t_node	*tmpbis;

	tmp = *a;
	if (tmp->next == NULL)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	tmpbis = tmp->next;
	tmp->next = NULL;
	tmpbis->next = *a;
	*a = tmpbis;
	if (state == 1)
		ft_printf("rra\n");
	else if (state == 2)
		ft_printf("rrb\n");
}
