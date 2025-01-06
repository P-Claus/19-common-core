/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:26:24 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/18 22:45:11 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*top_b;

	if (*head_b == NULL)
		return ;
	top_b = *head_b;
	*head_b = (*head_b)->next;
	if (*head_b)
		(*head_b)->prev = NULL;
	top_b->next = *head_a;
	top_b->prev = NULL;
	if (*head_a)
		(*head_a)->prev = top_b;
	*head_a = top_b;
	ft_printf("pa\n");
}
