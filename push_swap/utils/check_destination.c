/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_destination.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:35:45 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/12 16:47:04 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_destination(t_node **head, int new_value)
{
	int		count;
	t_node	*old_head;
	int		lowest_int;

	count = 0;
	old_head = *head;
	lowest_int = return_lowest_int(head);
	while ((*head))
	{
		if ((*head)->value == lowest_int && new_value < (*head)->value)
			break ;
		if ((*head)->prev && new_value > (*head)->prev->value
			&& new_value < (*head)->value)
			break ;
		if ((*head)->prev && (*head)->value == lowest_int
			&& new_value > (*head)->value && new_value > (*head)->prev->value)
			break ;
		count++;
		if ((*head)->next)
			*head = (*head)->next;
		else
			break ;
	}
	*head = old_head;
	return (count);
}
