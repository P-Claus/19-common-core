/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:58:44 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/07 18:14:35 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi_long(const char *str)
{
	long	result;
	int		iter;
	int		sign;

	iter = 0;
	sign = 1;
	result = 0;
	while (str[iter] && ((str[iter] >= 9 && str[iter] <= 13) || \
				str[iter] == 32))
		iter++;
	if (str[iter] == '+' || str[iter] == '-')
	{
		if (str[iter] == '-')
			sign = -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0')
	{
		result = result * 10 + str[iter] - '0';
		iter++;
	}
	return (result * sign);
}
