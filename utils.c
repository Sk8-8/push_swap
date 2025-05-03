/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:59:32 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/03 18:31:14 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksizesign(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i ++;
	while ((str[i] != '\0' && i < 12) && (str[i] >= '0' && str[i] <= '9'))
		i ++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	checkintlimits(long num)
{
	long	check;

	if (num < 0)
	{
		check = -2147483648;
		if (num < check)
			return (1);
	}
	else
	{
		check = 2147483647;
		if (num > check)
			return (1);
	}
	return (0);
}

long	lval(char *str)
{
	long	sign;
	long	res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	if (str[0] == '-')
		sign = -1;
	while (str[i] < '0' || str[i] > '9')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i ++;
	}
	return (res * sign);
}

int	checkduplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (j == i)
				j ++;
			if (j == argc)
				break ;
			if (lval(argv[j]) == lval(argv[i]))
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

void	checkerror(int argc, char **argv)
{
	int	i;
	int	res;

	i = 2;
	res = 0;
	while (i <= argc)
	{
		res += (checksizesign(argv[i - 1]) + checkintlimits(lval(argv[i - 1])));
		i ++;
	}
	res += checkduplicates(argc, argv);
	if (res != 0)
	{
		ft_printf("Error\n");
		exit (0);
	}
}
