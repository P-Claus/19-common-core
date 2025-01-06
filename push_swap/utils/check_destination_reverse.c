/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_destination_reverse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:17:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/20 21:05:12 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_destination_reverse(t_node **head, int new_value, int count)
{
	int	highest_int;

	highest_int = return_highest_int(head);
	while ((*head))
	{
		if ((*head)->value == highest_int && new_value > (*head)->value)
			break ;
		if ((*head)->prev && new_value < (*head)->prev->value
			&& new_value > (*head)->value)
			break ;
		if ((*head)->prev && (*head)->value == highest_int
			&& new_value < (*head)->value && new_value < (*head)->prev->value)
			break ;
		count++;
		if ((*head)->next)
			*head = (*head)->next;
		else
		{
			count = 0;
			break ;
		}
	}
	tail_to_head(head);
	return (count);
}
