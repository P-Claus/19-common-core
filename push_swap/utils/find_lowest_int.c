/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:04:16 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 18:05:54 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_lowest_int(t_node **head_a)
{
	int		lowest;
	int		count;
	t_node	*old_head;

	lowest = INT_MAX;
	count = 0;
	old_head = *head_a;
	while (*head_a)
	{
		if ((*head_a)->value < lowest)
			lowest = (*head_a)->value;
		*head_a = (*head_a)->next;
	}
	*head_a = old_head;
	while ((*head_a))
	{
		if ((*head_a)->value == lowest)
			break ;
		count++;
		*head_a = (*head_a)->next;
	}
	*head_a = old_head;
	return (count);
}
