/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:02:56 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/17 21:50:21 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_node **head)
{
	t_node	*old_head;
	t_node	*current;

	if (!(*head)->next && !(*head)->prev)
		return ;
	old_head = *head;
	*head = (*head)->next;
	current = *head;
	if (current->prev)
		current->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = old_head;
	old_head->next = NULL;
	old_head->prev = current;
	ft_printf("ra\n");
}
