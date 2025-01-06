/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:01:47 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/19 16:25:18 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rb(t_node **head)
{
	t_node	*old_head;
	t_node	*current;

	if (!(*head)->next && !(*head)->prev)
		return ;
	old_head = *head;
	if ((*head)->next)
		*head = (*head)->next;
	current = *head;
	if (current->prev)
		current->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = old_head;
	old_head->next = NULL;
	old_head->prev = current;
	ft_printf("rb\n");
}
