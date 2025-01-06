/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:58:07 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/08 13:58:10 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_four(t_node **head_a, t_node **head_b)
{
	int	destination;

	if (check_if_list_is_sorted(head_a) == 0)
		return ;
	tail_to_head(head_a);
	pb(head_a, head_b);
	sort_three(head_a);
	destination = check_destination(head_a, (*head_b)->value);
	sort_five_fourth_int(head_a, head_b, destination);
	sort_five_final_sort(head_a);
}
