/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_lowest_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:18:29 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 18:06:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	return_lowest_int(t_node **head_a)
{
	int		lowest;
	t_node	*old_head;

	lowest = INT_MAX;
	old_head = *head_a;
	while (*head_a)
	{
		if ((*head_a)->value < lowest)
			lowest = (*head_a)->value;
		*head_a = (*head_a)->next;
	}
	*head_a = old_head;
	return (lowest);
}
