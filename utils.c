/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:59:32 by kguillem          #+#    #+#             */
/*   Updated: 2025/04/13 18:57:34 by kguillem         ###   ########.fr       */
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

int	checkintlimits(char	*str)
{
	char	*check;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	if (str[0] == '-')
		check = "-2147483648";
	if (str[0] == '+')
		check = "+2147483647";
	else
		check = "2147483647";
	if (i > 9)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] > check[i])
				return (1);
			i ++;
		}
	}
	return (0);
}

int	pushswap_atoi(char *str)
{
	int	sign;
	int	res;
	int	i;

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
			if (pushswap_atoi(argv[j]) == pushswap_atoi(argv[i]))
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
		res += (checksizesign(argv[i - 1]) + checkintlimits(argv[i - 1]));
		i ++;
	}
	res += checkduplicates(argc, argv);
	if (res != 0)
	{
		ft_printf("Error\n");
		exit (0);
	}
}
