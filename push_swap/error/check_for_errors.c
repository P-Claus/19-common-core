/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:16:55 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/22 09:36:22 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_for_errors(char **argv)
{
	if (error_check_duplicates(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (error_check_integer(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (error_check_for_int(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (error_check_empty_string(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	error_check_integer(char **argv)
{
	int	count;

	count = 1;
	while (argv[count] != NULL)
	{
		if (is_valid_int(argv[count]) == 1)
			return (1);
		count++;
	}
	return (0);
}

int	error_check_duplicates(char **argv)
{
	int	count;
	int	i;

	count = 1;
	i = 1;
	while (argv[count])
	{
		while (argv[i])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[count]) && i != count)
				return (1);
			i++;
		}
		i = 1;
		count++;
	}
	return (0);
}

int	error_check_for_int(char **argv)
{
	long	nb;
	int		count;

	count = 0;
	nb = 0;
	while (argv[count] != NULL)
	{
		nb = ft_atoi_long(argv[count]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		count++;
	}
	return (0);
}

int	error_check_empty_string(char **argv)
{
	if (argv[1][0] == 0)
		return (1);
	else
		return (0);
}
