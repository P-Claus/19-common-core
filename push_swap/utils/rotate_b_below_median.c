/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b_below_median.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:44:24 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/21 17:49:10 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_b_to_be_in_position(t_node **head_a, t_node **head_b,
		int *index_b, int *iter_b)
{
	if (*index_b < (count_nodes(head_b) + 1) / 2)
	{
		while (*iter_b <= *index_b)
		{
			rb(head_b);
			(*iter_b)++;
		}
	}
	else if (*index_b >= (count_nodes(head_b) + 1) / 2)
	{
		while (*iter_b < (count_nodes(head_b) - *index_b) - 1)
		{
			rrb(head_b);
			(*iter_b)++;
		}
	}
	pb(head_a, head_b);
}
