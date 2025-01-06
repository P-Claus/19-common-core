/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps_to_be_in_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:07:52 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/20 21:04:50 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_steps_to_be_in_position(t_node **head_a, t_node **head_b)
{
	int	count_a;
	int	count_b;
	int	cheapest_steps_to_push;

	count_a = count_nodes_and_update_index(head_a);
	count_b = count_nodes_and_update_index(head_b);
	cheapest_steps_to_push = INT_MAX;
	update_median(head_a, count_a);
	update_median(head_b, count_b);
	while (*head_a)
	{
		(*head_a)->destination = check_destination_reverse(head_b,
				(*head_a)->value, 0);
		update_cheapest_to_push_member(head_a, head_b, count_a, count_b);
		if ((*head_a)->cheapest_to_push < cheapest_steps_to_push)
			cheapest_steps_to_push = (*head_a)->cheapest_to_push;
		if ((*head_a)->next)
			*head_a = (*head_a)->next;
		else
			break ;
	}
	tail_to_head(head_a);
	return (cheapest_steps_to_push);
}
