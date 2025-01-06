/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_highest_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:08:46 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/21 11:08:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	return_highest_int(t_node **head)
{
	int		highest;
	t_node	*old_head;

	highest = INT_MIN;
	old_head = *head;
	while (*head)
	{
		if ((*head)->value > highest)
			highest = (*head)->value;
		*head = (*head)->next;
	}
	*head = old_head;
	tail_to_head(head);
	return (highest);
}
