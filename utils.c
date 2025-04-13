/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:59:32 by kguillem          #+#    #+#             */
/*   Updated: 2025/04/02 16:34:48 by kguillem         ###   ########.fr       */
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
	int	i;

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

	i = 2;
	if (argc < 3)
		return (0);
	else
	{
		j = 1;
		while (i <= argc)
		{
			while (j <= argc)
			{
				if (j == i)
					j ++;
				else if (pushswap_atoi(argv[i]) == pushswap_atoi(argv[j]))
					return (1);
				j ++;
			}
			i ++;
		}
	}
	return (0);
}
			
void	checkerror(int argc, char **argv)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (i <= argc)
	{
		res += checksizesign(argv[i]);
		res += checkintlimits(argv[i]);
		i ++;
	}
	res += checkduplicates(argc, argv);
	if (res != 0)
	{
		ft_printf("Error\n");
		exit (0);
	}
}
