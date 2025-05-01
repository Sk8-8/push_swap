/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:42:13 by kguillem          #+#    #+#             */
/*   Updated: 2025/04/13 18:00:05 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*listtolast(t_node *list);
void	listaddtoback(t_node **list, t_node *new);
void	filllist(t_node **list, int argc, char **argv);
void	freelist(t_node **list);
void	checkerror(int argc, char **argv);
void	swap(int *a, int *b);
void	bubblesort(int *tab, t_node *tmp);
void	bubblesortindex(t_node *stack);
void	swapfirstnode(t_node *a);
void	pushnode(t_node **a, t_node **b, int state);
void	rotatenode(t_node **a, int state);
void	reverserotatenode(t_node **a, int state);
void	raddix(t_node **a, t_node **b, int i);
void	sort(t_node **a);
void	error(void);
void	three(t_node *a);
void	five(t_node **a, t_node **b);
void	radix(t_node **a, t_node **b, int i);
int		get_greater(t_node *a);
int		countnodes(t_node *list);
int		checksizesign(char *str);
int		checkintlimits(char *str);
int		pushswap_atoi(char *str);
int		checkduplicates(int argc, char **argv);
int		indextab(int *tab, int val);
int		sortedcheck(t_node *a);
int		main(int argc, char **argv);

#endif//PUSH_SWAP_H
