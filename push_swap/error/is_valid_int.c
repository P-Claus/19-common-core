/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:01:55 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/07 18:12:50 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		if (str[1] == '\0')
			return (1);
		i = 1;
	}
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (1);
		i++;
	}
	return (0);
}
