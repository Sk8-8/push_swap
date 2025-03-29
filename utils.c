/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:59:32 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/29 21:03:17 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	checksizesign(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[1] == '+' || str[1] == '-')
			return (printf("Error\n"));
		i ++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') && i < 12)
			i ++;
		else
			return (printf("Error\n"));
	}
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
				return (printf("Error\n"));
			i ++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (printf("Error\n"));
	i = checksizesign(argv[1]) + checkintlimits(argv[1]);
	printf("%d\n", i);
	return (0);
}
