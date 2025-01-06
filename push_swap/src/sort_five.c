/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:45:01 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/22 09:24:28 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five(t_node **head_a, t_node **head_b)
{
	int	destination;

	if (check_if_list_is_sorted(head_a) == 0)
		return ;
	tail_to_head(head_a);
	pb(head_a, head_b);
	pb(head_a, head_b);
	sort_three(head_a);
	destination = check_destination(head_a, (*head_b)->value);
	sort_five_fourth_int(head_a, head_b, destination);
	destination = check_destination(head_a, (*head_b)->value);
	sort_five_fifth_int(head_a, head_b, destination);
	sort_five_final_sort(head_a);
}
