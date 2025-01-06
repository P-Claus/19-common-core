/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:17:00 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/14 18:14:20 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_median(t_node **head, int count)
{
	int	median;
	int	iter;

	median = count / 2;
	iter = 0;
	while (*head)
	{
		set_median(head, iter, count, median);
		iter++;
		if ((*head)->next)
			*head = (*head)->next;
		else
			break ;
	}
	tail_to_head(head);
}
