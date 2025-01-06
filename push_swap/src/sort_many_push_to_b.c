/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_push_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:10:01 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/21 17:48:42 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_a_below_median(t_fp *fa, t_node **head_a, t_node **head_b)
{
	while (fa->iter_a < fa->index_a)
	{
		tail_to_head(head_a);
		if (fa->iter_b <= fa->index_b && fa->index_b < (count_nodes(head_b) + 1)
			/ 2)
		{
			rr(head_a, head_b);
			fa->iter_a++;
			fa->iter_b++;
		}
		else
		{
			ra(head_a);
			fa->iter_a++;
		}
	}
}

static void	rotate_a_above_median(t_fp *fa, t_node **head_a, t_node **head_b)
{
	fa->index_a = count_nodes(head_a) - (*head_a)->index;
	while (fa->iter_a < fa->index_a)
	{
		tail_to_head(head_a);
		if (fa->iter_b < (count_nodes(head_b) - fa->index_b) - 1
			&& fa->index_b >= (count_nodes(head_b) + 1) / 2)
		{
			rrr(head_a, head_b);
			fa->iter_a++;
			fa->iter_b++;
		}
		else
		{
			rra(head_a);
			fa->iter_a++;
		}
	}
}

void	sort_many_push_to_b(t_node **head_a, t_node **head_b,
		int cheapest_steps_to_push)
{
	t_fp	fa;

	fa.iter_a = 0;
	fa.iter_b = 0;
	while ((*head_a))
	{
		fa.index_a = (*head_a)->index;
		fa.index_b = (*head_a)->destination - 1;
		if ((*head_a)->cheapest_to_push == cheapest_steps_to_push)
		{
			if ((*head_a)->above_median == 0)
				rotate_a_below_median(&fa, head_a, head_b);
			else if ((*head_a)->above_median == 1)
				rotate_a_above_median(&fa, head_a, head_b);
			return ((void)rotate_b_to_be_in_position(head_a, head_b,
					&fa.index_b, &fa.iter_b));
		}
		if ((*head_a)->next)
			*head_a = (*head_a)->next;
		else
			break ;
	}
	tail_to_head(head_a);
}
