/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_fifth_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:08:38 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 21:13:52 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five_fifth_int(t_node **head_a, t_node **head_b, int destination)
{
	if (destination == 1)
	{
		ra(head_a);
		pa(head_a, head_b);
	}
	else if (destination == 2)
	{
		ra(head_a);
		ra(head_a);
		pa(head_a, head_b);
	}
	else if (destination == 3)
	{
		rra(head_a);
		pa(head_a, head_b);
	}
	else if (destination == 0 || destination == 4)
		pa(head_a, head_b);
}
