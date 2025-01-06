/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_fourth_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:03:51 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 21:06:44 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five_fourth_int(t_node **head_a, t_node **head_b, int destination)
{
	if (destination == 1)
	{
		pa(head_a, head_b);
		sa(*head_a);
	}
	else if (destination == 2)
	{
		rra(head_a);
		pa(head_a, head_b);
	}
	else if (destination == 0 || destination == 3)
		pa(head_a, head_b);
}
