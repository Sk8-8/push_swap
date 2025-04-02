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

#include <stdio.h>

int	checksizesign(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i ++;
	while ((str[i] != '\0' && i < 12) && (str[i] >= '0' && str[i] <= '9'))
			i ++;
	if (str[i] != '\0')
			return (printf("Error1\n"));
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
				return (printf("Error2\n"));
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
/*
void	printintbinary(int num)
{
	char	binary[32];
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((num << i) & 2147483648)
			binary[i] = '1';
		else
			binary[i] = '0';
		i ++;
	}
	printf("%s\n", binary);
}

doesn t work for negatives numbers precedented by '0'
int	noduptrim(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[0] == '+')
		i ++;
	if (s2[0] == '+')
		j ++;
	while (s1[i] == '0')
		i ++;
	while (s2[j] == '0')
		j ++;
	while (s1[i] == s2[j] && (s1[i] != '\0' || s2[j] != '\0'))
	{
		i ++;
		j ++;
	}
	if (s1[i] == '\0' && s2[j] == '\0')
		return (printf("Error3\n"));
	else
		return (0);
}*/
/*
// doesn t work for negatives numbers precedented by '0'
int	checkduplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (j != argc)
	{
		if (i == j)
			i ++;
		if (i == argc)
		{
			i = 1;
			j ++;
		}
		if (j == argc)
			break ;
		if (noduptrim(argv[i], argv[j]) == 0)
			i ++;
		else
			return (6);
	}
	return (0);
}*/

int	main(int argc, char **argv)
{
	int	i = 1;
	int num;

	while (i != argc)
	{
		num = pushswap_atoi(argv[i]);
		printintbinary(num);
		i++;
	}
/*
	int	a;
	int	i;

	i = 1;
	if (argc < 3)
		return (printf("%s\n", argv[argc - 1]));
	while (i != argc)
	{
		a = checksizesign(argv[i]) + checkintlimits(argv[i]);
		printf("%d\n", a);
		if (a > 0)
			return (1);
		i ++;
	}
	a = checkduplicates(argc, argv);
	printf("%d\n", a);
*/
	return (0);
}
