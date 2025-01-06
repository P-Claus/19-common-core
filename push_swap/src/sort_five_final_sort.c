/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_final_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:17:49 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 20:35:14 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five_final_sort(t_node **head)
{
	int	lowest_int_position;

	lowest_int_position = find_lowest_int(head);
	if (lowest_int_position == 1)
	{
		ra(head);
	}
	if (lowest_int_position == 2)
	{
		ra(head);
		ra(head);
	}
	if (lowest_int_position == 3)
	{
		rra(head);
		rra(head);
	}
	if (lowest_int_position == 4)
		rra(head);
}
