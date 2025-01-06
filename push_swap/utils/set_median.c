/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:09:56 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/21 11:09:54 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_median(t_node **head, int iter, int count, int median)
{
	if (count % 2 == 0)
	{
		if (iter < median)
			(*head)->above_median = 0;
		else
			(*head)->above_median = 1;
	}
	else if (count % 2 != 0)
	{
		if (iter <= median)
			(*head)->above_median = 0;
		else
			(*head)->above_median = 1;
	}
}
