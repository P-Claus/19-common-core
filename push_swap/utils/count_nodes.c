/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:49:54 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/21 11:07:08 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_nodes(t_node **head)
{
	int	count;

	count = 0;
	while (*head)
	{
		count++;
		if ((*head)->next)
			*head = (*head)->next;
		else
			break ;
	}
	tail_to_head(head);
	return (count);
}
