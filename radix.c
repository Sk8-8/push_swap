/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:13:50 by kguillem          #+#    #+#             */
/*   Updated: 2025/04/02 17:52:02 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//chained list struct
typedef struct node {
	int val;
	char *rank;
	struct node * next;
} t_node;

//verification of the struct content
void	print_list(t_node * head)
{
	t_node * current = head;

	while (current != NULL)
	{
		printf("value stored : %d\n", current->val);
		current = current->next;
	}
}

void	push(t_node * head, int val)
{
	t_node * current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = (t_node *) malloc(sizeof(t_node));
	current->next->val = val;
	current->next->next = NULL;
}

void	push(t_node **head, int val)
{
	t_node * new_node;
	new_node = (node_t *) malloc(sizeof(t_node));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

int	pop(t_node **head)
{
	int retval = -1;
	t_node * next_node = NULL;

	if (*head == NULL)
		return (-1);

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return (retval);
}

int	remove_last(t_node * head)
{
	int	retval = 0;
	if (head->next == NULL)
	{
		retval = head->val;
		free(head);
		return (retval);
	}
	t_node * current = head;
	while (current->next->next != NULL)
		current = current->next;
	retval = current->next->val;
	free(current->next);
	current->next = NULL;
	return (retval);
}

void	swap(t_node **stacka, int vala, t_node **stackb, int valb)
{
	
}
