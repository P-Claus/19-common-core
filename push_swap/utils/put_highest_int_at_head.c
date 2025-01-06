/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_highest_int_at_head.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:58:48 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/20 21:02:35 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_highest_int_at_head(t_node **head)
{
	int	highest_int;
	int	above_median;

	highest_int = return_highest_int(head);
	update_median(head, count_nodes(head));
	while ((*head)->value != highest_int)
	{
		if ((*head)->next)
			*head = (*head)->next;
		else
			break ;
	}
	above_median = (*head)->above_median;
	tail_to_head(head);
	if (above_median == 0)
	{
		while ((*head)->value != highest_int)
			rb(head);
	}
	if (above_median == 1)
	{
		while ((*head)->value != highest_int)
			rrb(head);
	}
}
