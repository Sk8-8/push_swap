/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:18:28 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/03 18:32:10 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*listtolast(t_node *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	listaddtoback(t_node **list, t_node *new)
{
	t_node	*last;

	if (!list || !new)
		return ;
	last = listtolast(*list);
	if (!last)
		*list = new;
	else
		last->next = new;
}

void	filllist(t_node **list, int argc, char **argv)
{
	int		i;
	t_node	*new;

	if (!list || !argv)
		return ;
	i = 1;
	while (i <= argc)
	{
		if (!argv[i])
			return ;
		new = malloc(sizeof(t_node));
		if (!new)
			return ;
		new->val = (int)lval(argv[i]);
		new->next = NULL;
		new->index = i;
		listaddtoback(list, new);
		i ++;
	}
}

void	freelist(t_node **list)
{
	t_node	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

int	countnodes(t_node *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i ++;
		list = list->next;
	}
	return (i);
}
