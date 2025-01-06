/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:13:45 by pclaus            #+#    #+#             */
/*   Updated: 2024/03/08 20:55:27 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_node *head_a, t_node *head_b)
{
	int	temp_a;
	int	temp_b;

	if (head_a == NULL || head_b == NULL)
		return ;
	temp_a = head_a->value;
	head_a->value = head_a->next->value;
	head_a->next->value = temp_a;
	temp_b = head_b->value;
	head_b->value = head_b->next->value;
	head_b->next->value = temp_b;
	ft_printf("ss\n");
}
