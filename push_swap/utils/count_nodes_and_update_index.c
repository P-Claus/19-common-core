/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nodes_and_update_index.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:35:13 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/19 11:58:05 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_nodes_and_update_index(t_node **head)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (*head)
	{
		count++;
		(*head)->index = index;
		index++;
		if ((*head)->next)
			*head = (*head)->next;
		else
			break ;
	}
	tail_to_head(head);
	return (count);
}
