/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:33:10 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/14 17:11:00 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_end(t_node **head, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = data;
	new_node->prev = *head;
	new_node->next = NULL;
	new_node->destination = 0;
	new_node->index = 0;
	if (new_node->prev != NULL && new_node->prev->next == NULL)
		new_node->prev->next = new_node;
	if (!*head)
		*head = new_node;
	else
	{
		(*head)->next = new_node;
		*head = new_node;
	}
}
